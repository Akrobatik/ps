// Title : 트윈 타워 (Easy)
// Link  : https://www.acmicpc.net/problem/35056 
// Time  : 92 ms
// Memory: 64704 KB

#include <bits/stdc++.h>

using namespace std;

constexpr int64_t kInf = 1e18;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<int> arr(n), brr(n - 1);
  for (auto& e : arr) cin >> e;
  for (auto& e : brr) cin >> e;

  vector<vector<array<int64_t, 2>>> memo(n + 1, vector<array<int64_t, 2>>(n + 1, {-kInf, -kInf}));
  memo[0][0][0] = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= i; j++) {
      memo[i + 1][j][0] = max<int64_t>({memo[i + 1][j][0], memo[i][j][0], memo[i][j][1]});
      if (memo[i][j][1] != -kInf) memo[i + 1][j + 1][0] = max<int64_t>(memo[i + 1][j + 1][0], memo[i][j][1] + arr[i] + brr[i - 1]);
      memo[i + 1][j + 1][1] = max<int64_t>({memo[i + 1][j + 1][1], memo[i][j][0] + arr[i], memo[i][j][1] + arr[i]});
    }
  }

  for (int i = 1; i <= n; i++) {
    int64_t maxx = 0;
    for (int j = 1; j <= n; j++) {
      maxx = max<int64_t>({maxx, memo[j][i][0], memo[j][i][1]});
    }
    cout << maxx << "\n";
  }

  return 0;
}