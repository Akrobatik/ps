// Title : 중앙값 구하기
// Link  : https://www.acmicpc.net/problem/2696 
// Time  : 4 ms
// Memory: 2688 KB

#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

using ordered_set = tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;

    cout << ((n + 1) >> 1) << "\n";

    ordered_set st;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
      int x;
      cin >> x;
      st.insert({x, i});
      if (i & 1) {
        cout << st.find_by_order(i >> 1)->first << " \n"[++cnt == 10];
        if (cnt == 10) cnt = 0;
      }
    }
    if (cnt) cout << "\n";
  }

  return 0;
}