// Title : 동전 2
// Link  : https://www.acmicpc.net/problem/2294 
// Time  : 0 ms
// Memory: 2060 KB

#include <bits/stdc++.h>

using namespace std;

constexpr int kInf = INT_MAX >> 1;

int memo[10001];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;
  vector<int> arr(n);
  for (auto& e : arr) cin >> e;
  sort(arr.begin(), arr.end());

  fill_n(memo + 1, k, kInf);
  for (int i = 1; i <= k; i++) {
    for (auto e : arr) {
      if (i < e) break;
      memo[i] = min<int>(memo[i], memo[i - e] + 1);
    }
  }
  cout << (memo[k] != kInf ? memo[k] : -1);

  return 0;
}
