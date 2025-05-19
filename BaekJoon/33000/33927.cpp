// Title : 나이트 오브 나이츠
// Link  : https://www.acmicpc.net/problem/33927 
// Time  : 20 ms
// Memory: 2024 KB

#include <bits/stdc++.h>

using namespace std;

constexpr pair<int, int> kDelta[] = {
    {-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {2, -1}, {2, 1}};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<vector<int>> board(n, vector<int>(n));
  for (auto& vec : board) {
    for (auto& e : vec) cin >> e;
  }

  int maxx = 0, limit = 1 << (n * n);
  for (int i = 1; i < limit; i++) {
    vector<int> idx;
    uint32_t x = i;
    for (; x; x -= x & (-x)) idx.push_back(countr_zero(x));

    bool check[4][4] = {};

    int sum = 0;
    bool ok = true;
    for (auto yx : idx) {
      int y = yx / n, x = yx % n;
      sum += board[y][x];
      check[y][x] = true;

      for (auto [dy, dx] : kDelta) {
        int yy = y + dy, xx = x + dx;
        if (0 <= yy && yy < n && 0 <= xx && xx < n && check[yy][xx]) {
          ok = false;
          break;
        }
      }
      if (!ok) break;
    }

    if (ok) maxx = max<int>(maxx, sum);
  }

  cout << maxx;

  return 0;
}