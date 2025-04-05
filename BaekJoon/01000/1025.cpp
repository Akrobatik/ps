// Title : 제곱수 찾기
// Link  : https://www.acmicpc.net/problem/1025
// Time  : 0 ms
// Memory: 2036 KB

#include <bits/stdc++.h>

using namespace std;

class Graph : public vector<uint8_t> {
 public:
  Graph(int w, int h) : vector<uint8_t>(w * h, 0), w_(w), h_(h) {}

  uint8_t& at(int y, int x) {
    return operator[](y * w_ + x);
  }

 private:
  int w_;
  int h_;
};

bool CheckPerfectSqr(int v) {
  int vv = (int)sqrt((double)v);
  return vv * vv == v;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int w, h;
  cin >> h >> w;

  Graph g(w, h);
  for (int y = 0; y < h; y++) {
    string line;
    cin >> line;
    for (int x = 0; x < w; x++) {
      g.at(y, x) = (uint8_t)(line[x] - '0');
    }
  }

  int result = -1;
  int max = w > h ? w : h;
  for (int sy = 0; sy < h; sy++) {
    for (int sx = 0; sx < w; sx++) {
      for (int vy = -h + 1; vy < h; vy++) {
        for (int vx = -w + 1; vx < w; vx++) {
          int v = (int)g.at(sy, sx);
          if (CheckPerfectSqr(v) && result < v) {
            result = v;
          }

          if (vx != 0 || vy != 0) {
            int x = sx + vx;
            int y = sy + vy;
            while (0 <= x && x < w && 0 <= y && y < h) {
              v *= 10;
              v += (int)g.at(y, x);

              if (CheckPerfectSqr(v) && result < v) {
                result = v;
              }

              x += vx;
              y += vy;
            }
          }
        }
      }
    }
  }

  cout << result << endl;

  return 0;
}