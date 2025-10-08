// Title : Programy
// Link  : https://www.acmicpc.net/problem/26754 
// Time  : 368 ms
// Memory: 9840 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> arr(n);
  for (auto& e : arr) cin >> e;
  sort(arr.begin(), arr.end(), greater<int>());

  int m;
  cin >> m;
  vector<int> brr(m);
  for (auto& e : brr) cin >> e;
  sort(brr.begin(), brr.end());

  for (auto e : brr) {
    if (!arr.empty() && arr.back() <= e) arr.pop_back();
  }
  cout << n - arr.size();

  return 0;
}