// Title : Counting Inversions
// Link  : https://www.acmicpc.net/problem/10090 
// Time  : 120 ms
// Memory: 5928 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> fwk(n + 1);

  auto Update = [&](int i) {
    for (; i <= n; i += i & (-i)) ++fwk[i];
  };
  
  auto Query = [&](int i) {
    int res = 0;
    for (; i; i -= i & (-i)) res += fwk[i];
    return res;
  };

  int64_t ans = 0;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    ans += i - Query(x);
    Update(x);
  }
  cout << ans;

  return 0;
}
