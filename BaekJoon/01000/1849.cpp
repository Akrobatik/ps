// Title : 순열
// Link  : https://www.acmicpc.net/problem/1849 
// Time  : 68 ms
// Memory: 7172 KB

#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

using ordered_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  ordered_set st;
  for (int i = 0; i < n; i++) {
    st.insert(i);
  }

  vector<int> arr(n);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    auto it = st.find_by_order(x);
    arr[*it] = i + 1;
    st.erase(it);
  }

  for (auto e : arr) cout << e << "\n";

  return 0;
}
