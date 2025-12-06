// Title : 헌혈 대전
// Link  : https://www.acmicpc.net/problem/34892 
// Time  : 44 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int xyz, a, b, c, d, e, f, g, h;
  cin >> xyz >> a >> b >> c >> d >> e >> f >> g >> h;

  int cnt = 0;
  int xx, yy, zz;
  for (int x = 0; x <= xyz; x++) {
    int yz = xyz - x;
    for (int y = 0; y <= yz; y++) {
      int z = yz - y;
      if ((a * x + b * y + c * z == d) && (e * x + f * y + g * z == h)) {
        ++cnt;
        xx = x, yy = y, zz = z;
      }
    }
  }
  cout << (cnt == 0 ? 2 : (cnt == 1 ? 0 : 1)) << "\n";
  if (cnt == 1) cout << xx << " " << yy << " " << zz;

  return 0;
}