// Title : 사각형 개수 세기
// Link  : https://www.acmicpc.net/problem/34316 
// Time  : 40 ms
// Memory: 2412 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  int swp = 0;
  if (n > m) swap(n, m), swp = 1;

  vector<int> mat(n * m);
  for (auto& e : mat) cin >> e;

  auto Get = [&](int y, int x) {
    int idx = (swp ? x * n + y : y * m + x);
    return mat[idx];
  };

  int64_t all = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      int64_t cnt[20] = {};
      for (int k = 0; k < m; k++) {
        ++cnt[Get(i, k) + Get(j, k)];
      }

      int64_t sum = 0;
      for (int k = 2; k <= 9; k++) {
        sum += cnt[k] * cnt[20 - k];
      }
      sum += (cnt[10] * (cnt[10] - 1)) >> 1;
      all += sum;
    }
  }
  cout << all;

  return 0;
}