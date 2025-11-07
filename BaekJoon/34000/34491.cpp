// Title : Monster Fighting
// Link  : https://www.acmicpc.net/problem/34491 
// Time  : 896 ms
// Memory: 29964 KB

#include <bits/stdc++.h>

using namespace std;

using tup = tuple<int, int, int, int, int, int>;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;

    set<pair<int, int>> st[2];
    for (int i = 0; i < n; i++) {
      int x, y;
      cin >> x >> y;
      st[y].insert({x, i});
    }

    auto Cmp = [&](const tup& lhs, const tup& rhs) {
      auto& [lbx, lby, lbi, lax, lay, lai] = lhs;
      auto& [rbx, rby, rbi, rax, ray, rai] = rhs;
      int64_t lv = (int64_t)lbx * rax, rv = (int64_t)rbx * lax;
      return lv < rv || (lv == rv && lhs < rhs);
    };

    priority_queue<tup, vector<tup>, decltype(Cmp)> pq(Cmp);
    for (int i = 0; i < n; i++) {
      int bx, by;
      cin >> bx >> by;
      auto it = st[by].lower_bound({(bx + 1) >> 1, 0});
      if (it != st[by].end()) {
        auto [ax, ai] = *it;
        pq.push({bx, by, i, ax, by, ai});
      }
      auto jt = st[by ^ 1].lower_bound({bx, 0});
      if (jt != st[by ^ 1].end()) {
        auto [ax, ai] = *jt;
        pq.push({bx, by, i, ax, by ^ 1, ai});
      }
    }

    vector<int8_t> aut(n), but(n);
    while (!pq.empty()) {
      auto [bx, by, bi, ax, ay, ai] = pq.top();
      pq.pop();

      if (but[bi]) continue;

      if (aut[ai]) {
        auto it = st[ay].upper_bound({ax, ai});
        if (it != st[ay].end()) {
          auto [aax, aai] = *it;
          pq.push({bx, by, bi, aax, ay, aai});
        }
      } else {
        st[ay].erase({ax, ai});
        aut[ai] = but[bi] = 1;
      }
    }

    cout << (*min_element(but.begin(), but.end()) == 1 ? "YES\n" : "NO\n");
  }

  return 0;
}