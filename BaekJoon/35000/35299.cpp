// Title : 감정 압축
// Link  : https://www.acmicpc.net/problem/35299 
// Time  : 396 ms
// Memory: 519880 KB

#include <bits/stdc++.h>

using namespace std;

constexpr int kInf = 1e9;

int memo[76][76][151][2][76];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  int f;
  cin >> s >> f;

  int n = s.size() >> 1;
  vector<int> arr(n);
  for (int i = 0; i < n; i++) {
    arr[i] = (s[i << 1 | 1] == ')');
  }

  fill_n((int*)memo, sizeof(memo) / sizeof(int), kInf);
  memo[0][0][f][0][0] = 0;
  memo[0][0][f][1][0] = 0;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= f; j++) {
      for (int k = 0; k <= f * 2; k++) {
        for (int l = 0; l < 2; l++) {
          for (int m = 0; m <= n; m++) {
            int cur = memo[i][j][k][l][m];
            if (cur >= kInf) continue;

            for (int x = 0; x < 2; x++) {
              int flip = arr[i] ^ x;
              int nj = j + flip;
              int nk = k + (!flip ? 0 : (arr[i] ? 1 : -1));
              int nm = (l == x ? m + 1 : 1);
              int add = 0;
              if (l == x) {
                if (nm == 1) {
                  add = 2;
                } else if (nm == 2 || nm == 10) {
                  add = 1;
                }
              } else {
                add = 2;
              }
              auto& nxt = memo[i + 1][nj][nk][x][nm];
              nxt = min<int>(nxt, cur + add);
            }
          }
        }
      }
    }
  }

  int minn = kInf;
  for (int i = 0; i <= f; i++) {
    for (int j = 0; j < 2; j++) {
      for (int k = 0; k <= n; k++) {
        minn = min<int>(minn, memo[n][i][f][j][k]);
      }
    }
  }
  cout << minn;

  return 0;
}