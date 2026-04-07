// Title : 오늘보다 더 기쁜 날은 남은 생에 많지 않을 것이다
// Link  : https://www.acmicpc.net/problem/35480 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  auto Pack = [](int yy, int mm, int dd) {
    return (yy << 9) | (mm << 5) | dd;
  };

  int sy, sm, sd, ey, em, ed;
  cin >> sy >> sm >> sd >> ey >> em >> ed;
  int st = Pack(sy, sm, sd);
  int en = Pack(ey, em, ed);

  int n;
  cin >> n;

  int val[1 << 9] = {};
  for (int i = 0; i < n; i++) {
    int yy, mm, dd;
    cin >> yy >> mm >> dd;

    val[(mm << 5) + dd] = yy;
  }

  auto Calc = [&](int yy, int mm, int dd) {
    int v = val[(mm << 5) + dd];
    return v ? yy - v : 0;
  };

  int cnt = 0, bnd = Calc(sy, sm, sd);
  for (int i = st + 1; i <= en; i++) {
    cnt += (bnd < Calc(i >> 9, (i >> 5) & 0xf, i & 0x1f));
  }
  cout << cnt;

  return 0;
}