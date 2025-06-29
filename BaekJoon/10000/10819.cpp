// Title : 차이를 최대로
// Link  : https://www.acmicpc.net/problem/10819 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> arr(n);
  for (auto& e : arr) cin >> e;

  vector<int> idx(n);
  iota(idx.begin(), idx.end(), 0);

  int maxx = INT_MIN;
  do {
    int cur = 0;
    for (int i = 1; i < n; i++) {
      cur += abs(arr[idx[i - 1]] - arr[idx[i]]);
    }
    maxx = max<int>(maxx, cur);
  } while (next_permutation(idx.begin(), idx.end()));

  cout << maxx;

  return 0;
}
