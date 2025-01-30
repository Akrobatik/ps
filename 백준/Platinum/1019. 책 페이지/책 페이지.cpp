#include <bits/stdc++.h>

using namespace std;

int ans[10];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  int v = 1;
  for (;;) {
    int dv = v * 10;
    auto d = div(n, dv);
    for (int i = 0; i < 10; i++) ans[i] += d.quot * v;
    int r = d.rem - v + 1;
    if (r < 0) ans[0] += r;
    for (int i = 1; i < 10 && r > 0; i++) {
      int a = min<int>(r, v);
      ans[i] += a;
      r -= a;
    }
    if (d.quot == 0) break;
    v = dv;
  }

  for (int i = 0; i < 10; i++) cout << ans[i] << " ";

  return 0;
}
