// Title : 구간 NOT 과 단일 NOT
// Link  : https://www.acmicpc.net/problem/34699 
// Time  : 4 ms
// Memory: 5592 KB

#include <bits/stdc++.h>

using namespace std;

constexpr int64_t kInf = 1e18;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  string s1, s2;
  int64_t c1, c2;
  cin >> n >> s1 >> s2 >> c1 >> c2;

  vector<array<int64_t, 4>> memo(n + 1, {kInf, kInf, kInf, kInf});
  memo[n][0] = 0;

  for (int i = n - 1; i >= 0; i--) {
    for (int j = 0; j < 4; j++) {
      int x1 = (s1[i] - '0') ^ (j & 1);
      int x2 = (s2[i] - '0') ^ (j >> 1);
      for (int k = 0; k < 2; k++) {
        int64_t w = k * c2;
        int xx1 = x1 ^ k, xx2 = x2 ^ k;
        int y = j;
        if (xx1 == 0) y ^= 1, w += c1;
        if (xx2 == 0) y ^= 2, w += c1;
        memo[i][y] = min<int64_t>(memo[i][y], memo[i + 1][j] + w);
      }
    }
  }
  cout << *min_element(memo[0].begin(), memo[0].end());

  return 0;
}