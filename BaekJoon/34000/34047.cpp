// Title : 지옥도
// Link  : https://www.acmicpc.net/problem/34047 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

constexpr int kMax = 1e9;
constexpr int kQuad = kMax >> 2;

int GetX(int n, int m) {
  if (m == 1) return 0;
  if (m != 2 || n <= kQuad * 2 + 4 || n % 3 != 1) return n;

  bool ok = true;
  int x = n - 2, y = 2;
  for (int i = 1; ok && i * i <= kMax * 2; i++) {
    int nv = (n / i) * i;
    int nl = nv + i - n, nr = n - nv;
    int xv = (x / i) * i;
    int xl = xv + i - x, xr = x - xv;
    int nm = min<int>(nl, nr) % m;
    int xy = min<int>(xl, xr) % y;
    ok = (nm == xy);
  }
  return ok ? x : x + 2;
}

int GetY(int n, int m) {
  if (m == 1) return 1;
  if (n <= kQuad * 2) return min<int>(n + 1, m);
  if (n <= kQuad * 3) return min<int>(kMax - n + 1, m);
  return min<int>(kQuad + (n - kQuad * 3) / 3 + 1, m);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  cout << GetX(n, m) << " " << GetY(n, m);

  return 0;
}
