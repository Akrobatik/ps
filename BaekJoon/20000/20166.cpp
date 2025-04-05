// Title : 문자열 지옥에 빠진 호석
// Link  : https://www.acmicpc.net/problem/20166
// Time  : 96 ms
// Memory: 13620 KB

#include <bits/stdc++.h>

using namespace std;

constexpr pair<int, int> kDelta[] = {
    {-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

constexpr int64_t kMod = 1e9 + 9;
constexpr int64_t kBase = 131;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int64_t p[6];
  p[0] = 1;
  for (int i = 0; i < 5; i++) {
    p[i + 1] = p[i] * kBase % kMod;
  }

  int n, m, k;
  cin >> n >> m >> k;
  char cells[10][10];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> cells[i][j];
    }
  }

  unordered_map<int64_t, int> hm;
  function<void(int, int, int, int64_t)> Calc = [&](int y, int x, int len, int64_t h) {
    if (len == 5) return;
    h = (h + p[len] * cells[y][x]) % kMod;
    ++hm[h];

    for (auto [dy, dx] : kDelta) {
      int yy = (y + dy + n) % n, xx = (x + dx + m) % m;
      Calc(yy, xx, len + 1, h);
    }
  };

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      Calc(i, j, 0, 0);
    }
  }

  string q;
  while (k--) {
    cin >> q;
    int nq = q.size();
    int64_t h = 0;
    for (int i = 0; i < nq; i++) {
      h = (h + p[i] * q[i]) % kMod;
    }
    cout << hm[h] << "\n";
  }

  return 0;
}
