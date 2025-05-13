// Title : 별 안에 별 안에 별 찍기
// Link  : https://www.acmicpc.net/problem/30678 
// Time  : 92 ms
// Memory: 11748 KB

#include <bits/stdc++.h>

using namespace std;

constexpr const char* kStr =
    "  *  "
    "  *  "
    "*****"
    " *** "
    " * * ";

constexpr array<pair<int, int>, 12> kArr = []() {
  array<pair<int, int>, 12> arr{};
  auto it = arr.begin();
  for (int i = 0; i < 25; i++) {
    if (kStr[i] != '*') continue;
    int y = i / 5, x = i % 5;
    *it++ = {y, x};
  }
  return arr;
}();

vector<string> board;

void Traverse(int y, int x, int n) {
  if (n == 5) {
    for (auto [dy, dx] : kArr) {
      board[y + dy][x + dx] = '*';
    }
    return;
  }

  n /= 5;
  for (auto [dy, dx] : kArr) {
    Traverse(y + dy * n, x + dx * n, n);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  if (n == 0) {
    cout << "*";
    return 0;
  }

  int x = 1;
  while (n--) x *= 5;
  board.resize(x, string(x, ' '));
  Traverse(0, 0, x);

  for (auto& e : board) {
    // while (!e.empty() && e.back() == ' ') e.pop_back();
    cout << e << "\n";
  }

  return 0;
}
