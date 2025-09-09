// Title : NMABCD
// Link  : https://www.acmicpc.net/problem/25461 
// Time  : 0 ms
// Memory: 2024 KB

#include <bits/stdc++.h>

using namespace std;

int Color(int y, int x) {
  return (y + x) & 1;
}

bool ColorCompatible(int n, int m, int sy, int sx, int ty, int tx) {
  if (n * m % 2 == 0) return Color(sy, sx) != Color(ty, tx);
  return Color(sy, sx) == 0 && Color(ty, tx) == 0;
}

bool CheckF1(int n, int m, int sy, int sx, int ty, int tx) {
  if (n == 1) {
    bool sb = (sx == 1 || sx == m);
    bool tb = (tx == 1 || tx == m);
    return !sb || !tb;
  }

  if (m == 1) {
    bool sb = (sy == 1 || sy == n);
    bool tb = (ty == 1 || ty == n);
    return !sb || !tb;
  }

  return false;
}

bool CheckF2(int n, int m, int sy, int sx, int ty, int tx) {
  if (abs(sy - ty) + abs(sx - tx) != 1) return false;
  if (n == 2) return !(sy == ty || (sx == 1 && tx == 1) || (sx == m && tx == m));
  if (m == 2) return !(sx == tx || (sy == 1 && ty == 1) || (sy == n && ty == n));
  return false;
}

bool CheckF2S(int n, int m, int sy, int sx, int ty, int tx) {
  if (min<int>(n, m) != 2) return false;

  int rn = n, rm = m;
  int rsy = sy, rsx = sx;
  int rty = ty, rtx = tx;
  if (rn > rm) swap(rn, rm), swap(rsy, rsx), swap(rty, rtx);
  if (rsx > rtx) swap(rsy, rty), swap(rsx, rtx);
  return (rsx == rtx) || (rsx == rtx - 1 && rsy != rty);
}

bool CheckF3(int n, int m, int sy, int sx, int ty, int tx) {
  if (min<int>(n, m) != 3) return false;

  int rn = n, rm = m;
  int rsy = sy, rsx = sx;
  int rty = ty, rtx = tx;
  if (rn > rm) swap(rn, rm), swap(rsy, rsx), swap(rty, rtx);
  if (rsx > rtx) swap(rsy, rty), swap(rsx, rtx);
  if ((rm & 1) || Color(rsy, rsx) != 1 || Color(rty, rtx) != 0) return false;
  return (rsy == 2 && rsx < rtx) || (rsy != 2 && rsx < rtx - 1);
}

bool CheckC0(int n, int m, int sy, int sx, int ty, int tx) {
  return ColorCompatible(n, m, sy, sx, ty, tx) && !CheckF1(n, m, sy, sx, ty, tx) && !CheckF2(n, m, sy, sx, ty, tx) && !CheckF3(n, m, sy, sx, ty, tx);
}

bool CheckC1(int n, int m, int sy, int sx, int ty, int tx) {
  bool even = ((n * m) % 2 == 0);
  bool same = (Color(sy, sx) == Color(ty, tx));
  return !CheckF1(n, m, sy, sx, ty, tx) && !CheckF2S(n, m, sy, sx, ty, tx) && ((even && same) || (!even && !same));
}

bool CheckC2(int n, int m, int sy, int sx, int ty, int tx) {
  bool odd = ((n * m) % 2 == 1);
  bool black = (Color(sy, sx) == 1 && Color(ty, tx) == 1);
  if (odd && black && !CheckF1(n, m, sy, sx, ty, tx) && !CheckF2S(n, m, sy, sx, ty, tx)) return true;
  if (ColorCompatible(n, m, sy, sx, ty, tx) && CheckF3(n, m, sy, sx, ty, tx)) return true;
  return false;
}

int CalcUpperBound(int n, int m, int sy, int sx, int ty, int tx) {
  int rn = n, rm = m;
  int rsy = sy, rsx = sx;
  int rty = ty, rtx = tx;
  if (rn > rm) swap(rn, rm), swap(rsy, rsx), swap(rty, rtx);
  if (rsx > rtx) swap(rsy, rty), swap(rsx, rtx);

  if (rsy == rty && rsx == rtx) return 1;
  if (CheckF1(n, m, sy, sx, ty, tx)) return rtx - rsx + 1;
  if (CheckF2S(n, m, sy, sx, ty, tx)) return max<int>(rsx + rtx, rm * 2 - rtx - rsx + 2);
  if (CheckC0(n, m, sy, sx, ty, tx)) return n * m;
  if (CheckC1(n, m, sy, sx, ty, tx)) return n * m - 1;
  if (CheckC2(n, m, sy, sx, ty, tx)) return n * m - 2;
  return 0;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n, m, sy, sx, ty, tx;
    cin >> n >> m >> sy >> sx >> ty >> tx;
    cout << CalcUpperBound(n, m, sy, sx, ty, tx) << "\n";
  }

  return 0;
}