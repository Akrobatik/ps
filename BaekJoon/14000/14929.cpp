// Title : 귀찮아 (SIB)
// Link  : https://www.acmicpc.net/problem/14929 
// Time  : 8 ms
// Memory: 2412 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, sum = 0;
  cin>> n;
  vector<int> arr(n);
  for (auto& e : arr) cin >> e, sum += e;

  int64_t ans = 0;
  for (auto e : arr) {
    ans += e * (sum - e);
  }
  cout << ans / 2;

  return 0;
}
