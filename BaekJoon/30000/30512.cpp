// Title : 조용히 완전히 영원히
// Link  : https://www.acmicpc.net/problem/30512 
// Time  : 72 ms
// Memory: 9128 KB

#include <bits/stdc++.h>

using namespace std;

using tup = tuple<int, int, int, int>;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<int> arr(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
  }

  int m;
  cin >> m;
  vector<tup> qr(m);
  for (int i = 0; i < m; i++) {
    int l, r, x;
    cin >> l >> r >> x;
    qr[i] = {x, i, l, r};
  }
  sort(qr.begin(), qr.end());

  set<int> st;
  for (int i = 1; i <= n; i++) {
    st.insert(i);
  }

  vector<int> fwd(m);
  for (auto [x, i, l, r] : qr) {
    auto it = st.lower_bound(l);
    while (it != st.end() && *it <= r) {
      int p = *it;
      it = st.erase(it);

      if (arr[p] > x) {
        arr[p] = x;
        ++fwd[i];
      }
    }
  }

  for (int i = 1; i < m; i++) {
    fwd[i] += fwd[i - 1];
  }

  for (int i = 1; i <= n; i++) {
    cout << arr[i] << " \n"[i == n];
  }
  for (int i = 0; i < m; i++) {
    cout << fwd[i] + n - fwd[m - 1] << " ";
  }

  return 0;
}