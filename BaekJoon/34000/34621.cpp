// Title : 제설 작업
// Link  : https://www.acmicpc.net/problem/34621 
// Time  : 1404 ms
// Memory: 18040 KB

#include <bits/stdc++.h>

using namespace std;

using tup = tuple<int64_t, int, int>;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  vector<vector<int>> mat(n, vector<int>(m));
  for (auto& vec : mat) {
    for (auto& e : vec) {
      cin >> e;
    }
  }

  vector<vector<int64_t>> sum(2, vector<int64_t>(max<int>(n, m)));
  for (int i = 0; i < n; i++) {
    int64_t s = 0;
    for (int j = 0; j < m; j++) {
      s += mat[i][j];
    }
    sum[0][i] = s;
  }
  for (int j = 0; j < m; j++) {
    int64_t s = 0;
    for (int i = 0; i < n; i++) {
      s += mat[i][j];
    }
    sum[1][j] = s;
  }

  set<tup> st;
  for (int i = 0; i < n; i++) st.insert({sum[0][i], i, 0});
  for (int i = 0; i < m; i++) st.insert({sum[1][i], i, 1});

  vector<vector<bool>> out(2, vector<bool>(max<int>(n, m)));

  int64_t maxx = 0;
  int nm = n + m;
  while (nm--) {
    auto it = *st.begin();
    auto [s, id, t] = it;

    out[t][id] = true;

    maxx = max<int64_t>(maxx, s);

    int limit = (t ? n : m);
    for (int i = 0; i < limit; i++) {
      int64_t old = sum[t ^ 1][i];
      sum[t ^ 1][i] -= mat[t ? i : id][t ? id : i];
      if (out[t ^ 1][i]) continue;
      auto jt = st.lower_bound({old, i, 0});
      st.erase(jt);
      st.insert({sum[t ^ 1][i], i, t ^ 1});
    }

    st.erase(it);
  }
  cout << maxx;

  return 0;
}
