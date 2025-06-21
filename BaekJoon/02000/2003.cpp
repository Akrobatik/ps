// Title : 수들의 합 2
// Link  : https://www.acmicpc.net/problem/2003 
// Time  : 0 ms
// Memory: 2180 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  vector<int> arr(n);
  for (auto& e : arr) cin >> e;

  int l = 0, r = 0;
  int ls = 0, rs = 0;
  int cnt = 0;
  while (l < n) {
    while (r < n && ls + m > rs) rs += arr[r++];
    if (ls + m == rs) ++cnt;
    ls += arr[l++];
  }
  cout << cnt;

  return 0;
}
