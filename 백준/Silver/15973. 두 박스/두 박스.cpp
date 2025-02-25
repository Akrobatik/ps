#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int ax1, ay1, ax2, ay2, bx1, by1, bx2, by2;
  cin >> ax1 >> ay1 >> ax2 >> ay2 >> bx1 >> by1 >> bx2 >> by2;

  int x1 = max<int>(ax1, bx1);
  int x2 = min<int>(ax2, bx2);
  int y1 = max<int>(ay1, by1);
  int y2 = min<int>(ay2, by2);

  if (x1 <= x2 && y1 <= y2) {
    constexpr const char* s[] = {"FACE", "LINE", "POINT"};
    cout << s[(x1 == x2) + (y1 == y2)];
  } else {
    cout << "NULL";
  }

  return 0;
}
