// Title : 동전 1
// Link  : https://www.acmicpc.net/problem/2293 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int memo[10001] = {1};

  int n, k;
  cin >> n >> k;
  vector<int> arr(n);
  for (auto& e : arr) cin >> e;
  sort(arr.begin(), arr.end());

  for (auto e : arr) {
    for (int i = e; i <= k; i++) {
      memo[i] += memo[i - e];
    }
  }
  cout << memo[k];

  return 0;
}
