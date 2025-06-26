// Title : 데이트 약속
// Link  : https://www.acmicpc.net/problem/34037 
// Time  : 20 ms
// Memory: 2160 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  vector<int> xrr(m + 1);
  vector<int64_t> yrr(m + 1);
  for (int i = 1; i <= m; i++) {
    cin >> xrr[i] >> yrr[i];
  }
  if (xrr[m] != n) {
    xrr.push_back(n);
    yrr.push_back(0);
    ++m;
  }

  for (int i = 1; i <= m; i++) {
    yrr[i] += yrr[i - 1];
  }

  vector<int64_t> memo(m + 1);
  for (int i = 1; i <= m; i++) {
    int64_t maxx = 0;
    for (int j = 0; j < i; j++) {
      int64_t d = xrr[i] - xrr[j];
      int64_t s = (d * (d + 1)) >> 1;
      int64_t m1 = memo[j] + s - (yrr[i] - yrr[j]);
      int64_t m2 = memo[j] + s - d - (yrr[i - 1] - yrr[j]);
      maxx = max<int64_t>({maxx, m1, m2});
    }
    memo[i] = maxx;
  }
  cout << memo[m];

  return 0;
}
