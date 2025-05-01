// Title : N번째 큰 수
// Link  : https://www.acmicpc.net/problem/2075 
// Time  : 396 ms
// Memory: 10812 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> arr(n * n);
  for (auto& e : arr) cin >> e;
  sort(arr.begin(), arr.end(), greater<>());
  cout << arr[n - 1];

  return 0;
}
