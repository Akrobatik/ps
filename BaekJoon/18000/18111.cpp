// Title : 마인크래프트
// Link  : https://www.acmicpc.net/problem/18111
// Time  : 116 ms
// Memory: 2996 KB

#include <bits/stdc++.h>

using namespace std;

int n, m, b;
int cells[500][500];

int Calc(int h) {
  int res = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (h > cells[i][j]) {
        res += h - cells[i][j];
      } else {
        res += ((cells[i][j] - h) << 1);
      }
    }
  }
  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m >> b;
  int64_t sum = b;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> cells[i][j];
      sum += cells[i][j];
    }
  }

  int maxx = sum / (n * m);
  int h, t = INT_MAX;
  for (int i = 0; i <= maxx; i++) {
    int v = Calc(i);
    if (t >= v) t = v, h = i;
  }
  cout << t << " " << h;

  return 0;
}
