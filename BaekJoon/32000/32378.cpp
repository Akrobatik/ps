// Title : 횃불이 키우기
// Link  : https://www.acmicpc.net/problem/32378 
// Time  : 68 ms
// Memory: 66928 KB

#include <bits/stdc++.h>

using namespace std;

constexpr int64_t kInf = 1e12;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k, s;
  cin >> n >> k >> s;

  if (k >= 40) {
    cout << "MEGA";
    return 0;
  }

  vector<int> arr(n);
  for (auto& e : arr) cin >> e;

  vector<vector<int64_t>> memo(k + 1, vector<int64_t>(n + 1, -kInf));
  memo[0][0] = s;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= k; j++) {
      if (memo[j][i] <= 0) continue;
      if (memo[j][i] >= kInf) {
        cout << "MEGA";
        return 0;
      }
      memo[j][i + 1] = max<int64_t>(memo[j][i + 1], memo[j][i] + arr[i]);
      if (j < k) memo[j + 1][i + 1] = max<int64_t>(memo[j + 1][i + 1], memo[j][i] << 1);
    }
  }

  int64_t maxx = -kInf;
  for (int i = 0; i <= k; i++) maxx = max<int64_t>(maxx, memo[i][n]);

  if (maxx <= 0) {
    cout << "-1";
  } else if (maxx * 10 <= kInf) {
    cout << maxx;
  } else {
    cout << "MEGA";
  }

  return 0;
}