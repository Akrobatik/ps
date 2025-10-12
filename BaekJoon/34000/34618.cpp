// Title : Puf!
// Link  : https://www.acmicpc.net/problem/34618 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

struct Board {
  Board() : color{}, life{} {}

  int Process(int t, int y, int x, int r) {
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        if (color[i][j]) {
          if (life[i][j] > 0) {
            life[i][j] -= 1;
          } else {
            color[i][j] = 0;
          }
        }
      }
    }

    int cnt = 0;
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        cnt += (color[i][j] != 0);
      }
    }
    if (cnt == 9) return 2;

    if (color[y][x]) return 3;
    color[y][x] = t;
    life[y][x] = r;

    int c1 = 0, c2 = 0, maxx = 0;
    for (int i = 0; i < 3; i++) {
      c1 += (color[i][i] == t && life[i][i] > 0);
      c2 += (color[i][2 - i] == t && life[i][2 - i] > 0);
    }
    maxx = max<int>({maxx, c1, c2});
    for (int i = 0; i < 3; i++) {
      c1 = c2 = 0;
      for (int j = 0; j < 3; j++) {
        c1 += (color[i][j] == t && life[i][j] > 0);
        c2 += (color[j][i] == t && life[j][i] > 0);
      }
      maxx = max<int>({maxx, c1, c2});
    }
    if (maxx == 3) return 1;

    return 0;
  }

  int color[3][3];
  int life[3][3];
};

constexpr const char* kName[3] = {"", "BLOOM", "STELLA"};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  Board board;

  int n;
  cin >> n;
  for (int i = 1, t = 1; i <= n; i++, t ^= 3) {
    int y, x, r;
    cin >> y >> x >> r, --y, --x;
    int o = board.Process(t, y, x, r);
    if (o == 0) continue;

    if (o == 1) {
      cout << i << " " << kName[t];
    } else if (o == 2) {
      cout << i << " NERIJESENO";
    } else if (o == 3) {
      cout << i << " ILEGALNO";
    }
    return 0;
  }
  cout << "U TIJEKU";

  return 0;
}