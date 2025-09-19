// Title : 데이터 구조
// Link  : https://www.acmicpc.net/problem/12899 
// Time  : 1120 ms
// Memory: 64596 KB

#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

using ordered_set = tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  ordered_set st;
  for (int i = 0; i < n; i++) {
    int cmd, x;
    cin >> cmd >> x;
    if (cmd == 1) {
      st.insert({x, i});
    } else {
      auto it = st.find_by_order(x - 1);
      cout << it->first << "\n";
      st.erase(it);
    }
  }

  return 0;
}
