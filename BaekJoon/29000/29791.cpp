// Title : 에르다 노바와 오리진 스킬
// Link  : https://www.acmicpc.net/problem/29791 
// Time  : 328 ms
// Memory: 9840 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  vector<int> arr(n), brr(m);
  for (auto& e : arr) cin >> e;
  for (auto& e : brr) cin >> e;
  sort(arr.begin(), arr.end());
  sort(brr.begin(), brr.end());

  int ac = 0, ar = 0;
  for (auto e : arr) {
    if (e < ar) continue;
    ++ac, ar = e + 100;
  }
  int bc = 0, br = 0;
  for (auto e : brr) {
    if (e < br) continue;
    ++bc, br = e + 360;
  }
  cout << ac << " " << bc;

  return 0;
}
