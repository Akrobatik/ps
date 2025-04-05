// Title : 루미의 진정한™ 보라색 찾기
// Link  : https://www.acmicpc.net/problem/33663
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int64_t hl, hr, sl, sr, vl, vr;
  cin >> hl >> hr >> sl >> sr >> vl >> vr;
  int64_t r, g, b;
  cin >> r >> g >> b;

  int64_t maxx = max<int64_t>({r, g, b});
  int64_t minn = min<int64_t>({r, g, b});
  int64_t v = maxx;
  int64_t s = (maxx - minn) * 255;
  int64_t h = (v == r ? 60 * (g - b) : v == g ? 60 * (b - r) + 120 * (maxx - minn) : 60 * (r - g) + 240 * (maxx - minn));
  if (h < 0) h += (maxx - minn) * 360;

  bool bv = (vl <= v && v <= vr);
  bool bs = (maxx * sl <= s && s <= maxx * sr);
  bool bh = ((maxx - minn) * hl <= h && h <= (maxx - minn) * hr);

  cout << ((bv && bs && bh) ? "Lumi will like it." : "Lumi will not like it.");

  return 0;
}
