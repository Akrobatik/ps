// Title : 커트라인
// Link  : https://www.acmicpc.net/problem/25305 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;
  vector<int> arr(n);
  for (auto& e : arr) cin >> e;
  sort(arr.begin(), arr.end(), greater<int>());
  cout << arr[k - 1];

  return 0;
}
