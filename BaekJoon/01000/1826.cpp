// Title : 연료 채우기
// Link  : https://www.acmicpc.net/problem/1826 
// Time  : 44 ms
// Memory: 2224 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<pair<int, int>> arr(n);
  for (auto& [a, b] : arr) cin >> a >> b;
  sort(arr.begin(), arr.end());
  int l, p;
  cin >> l >> p;

  vector<int> memo(n + 1, -1), mnxt(n + 1);
  memo[0] = p;
  int prv = 0;
  for (int i = 0; i < n; i++) {
    fill(mnxt.begin(), mnxt.end(), -1);
    auto [cur, add] = arr[i];
    int sub = cur - prv;
    for (int j = 0; j <= i; j++) {
      if (memo[j] < sub) continue; 
      mnxt[j] = max<int>(mnxt[j], memo[j] - sub);
      mnxt[j + 1] = max<int>(mnxt[j + 1], memo[j] - sub + add);
    }
    prv = cur;
    swap(memo, mnxt);
  }

  int idx = 0;
  while (idx <= n && memo[idx] < l - prv) ++idx;
  cout << (idx <= n ? idx : -1);

  return 0;
}
