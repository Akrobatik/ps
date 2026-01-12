// Title : Swap, then record
// Link  : https://www.acmicpc.net/problem/35110 
// Time  : 52 ms
// Memory: 3592 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<int> arr(n);
  for (auto& e : arr) cin >> e;

  auto memo = arr;
  sort(memo.begin(), memo.end());

  for (auto& e : arr) {
    e = lower_bound(memo.begin(), memo.end(), e) - memo.begin();
  }

  int64_t sum = 0;
  int idx = 0;
  while (idx < n) {
    int nxt = idx, bnd = arr[idx];
    while (nxt < bnd) bnd = max<int>(bnd, arr[++nxt]);
    sum += memo[nxt] - memo[idx];
    idx = nxt + 1;
  }
  cout << sum;

  return 0;
}