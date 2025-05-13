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

vector<string> board;

void Traverse(int y, int x, int n) {
  if (n == 5) {
    for (int i = 0; i < 25; i++) {
      int yy = y + i / 5, xx = x + i % 5;
      board[yy][xx] = kStr[i];
    }
    return;
  }

  n /= 5;
  for (int i = 0; i < 25; i++) {
    if (kStr[i] != '*') continue;
    int yy = y + (i / 5) * n, xx = x + (i % 5) * n;
    Traverse(yy, xx, n);
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
