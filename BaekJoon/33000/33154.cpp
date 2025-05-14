// Title : 데이터를 추가해 주세요.
// Link  : https://www.acmicpc.net/problem/33154 
// Time  : 0 ms
// Memory: 2024 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int m;
  cin >> m;

  vector<int64_t> fib{1, 1};
  for (int i = 2; i < 59; i++) {
    fib.push_back(fib[i - 2] + fib[i - 1]);
  }

  function<int64_t(int)> Find = [&](int n) {
    int64_t x = (int64_t)m * n;
    int idx = 58, last = -1;
    while (idx-- && x) {
      if (x >= fib[idx]) {
        x -= fib[idx];
        last = idx;
      }
    }
    if (last > 1) return (int64_t)m * n;
    return Find(n + 1);
  };

  int64_t x = Find(1);
  vector<int> arr;
  int idx = fib.size();
  while (idx-- && x) {
    if (x >= fib[idx]) {
      x -= fib[idx];
      arr.push_back(idx);
    }
  }

  vector<string> board(60, string(60, '#'));
  for (int i = 1; i < 59; i++) {
    board[0][i] = board[59][i] = board[i][0] = board[i][59] = '.';
  }
  board[0][0] = board[59][59] = '.';

  for (int i = 0; i < arr.size(); i++) {
    int y = arr[i], x = 2;
    if (i & 1) {
      for (; y < 58 && x < 58; y++, x++) {
        board[y][x] = board[y][x - 1] = '.';
      }
      if (y == 58) {
        board[y][x - 1] = board[y + 1][x - 1] = '.';
      } else {
        board[y][x - 1] = board[y][x] = board[y][x + 1] = '.';
      }
    } else {
      for (; y < 58 && x < 58; y++, x++) {
        board[59 - y][59 - x] = board[59 - y][59 - (x - 1)] = '.';
      }
      if (y == 58) {
        board[59 - y][59 - (x - 1)] = board[59 - (y + 1)][59 - (x - 1)] = '.';
      } else {
        board[59 - y][59 - (x - 1)] = board[59 - y][59 - x] = board[59 - y][59 - (x + 1)] = '.';
      }
    }
  }

  cout << board.size() << "\n";
  for (auto& s : board) cout << s << "\n";

  return 0;
}
