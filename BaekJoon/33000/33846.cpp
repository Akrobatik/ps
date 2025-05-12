// Title : 삽입 정렬을 해볼까
// Link  : https://www.acmicpc.net/problem/33846 
// Time  : 272 ms
// Memory: 5928 KB

#include <bits/stdc++.h>

using namespace std;


int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, t;
  cin >> n >> t;
  vector<int> arr(n);
  for (auto& e : arr) cin >> e;
  sort(arr.begin(), arr.begin() + t);
  for (auto e : arr) cout << e << " ";

  return 0;
}
