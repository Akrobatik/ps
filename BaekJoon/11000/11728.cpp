// Title : 배열 합치기
// Link  : https://www.acmicpc.net/problem/11728 
// Time  : 556 ms
// Memory: 9836 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  vector<int> arr(n + m);
  for (auto& e : arr) cin >> e;
  sort(arr.begin(), arr.end());
  for (auto e : arr) cout << e << " ";

  return 0;
}
