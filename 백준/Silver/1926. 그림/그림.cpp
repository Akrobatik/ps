#include <bits/stdc++.h>

using namespace std;

constexpr pair<int, int> kDelta[] = {
    {-1, 0},
    {1, 0},
    {0, -1},
    {0, 1}};

int n, m;
int8_t cells[500][500];

int Traverse(int y, int x) {
  int res = 1;
  for (auto [dy, dx] : kDelta) {
    int yy = y + dy, xx = x + dx;
    if (0 <= yy && yy < n && 0 <= xx && xx < m && cells[yy][xx]) {
      cells[yy][xx] = 0;
      res += Traverse(yy, xx);
    }
  }
  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      char c;
      cin >> c;
      cells[i][j] = c - '0';
    }
  }

  int maxx = 0, cnt = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (cells[i][j]) {
        cells[i][j] = 0;
        int sum = Traverse(i, j);
        if (maxx < sum) maxx = sum;
        ++cnt;
      }
    }
  }

  cout << cnt << "\n"
       << maxx;

  return 0;
}
