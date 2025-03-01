#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, s, m;
  cin >> n >> s >> m;
  queue<int> q;
  q.push(s);
  for (int i = 0; i < n; i++) {
    int v;
    cin >> v;
    set<int> st;
    int nq = q.size();
    while (nq--) {
      auto x = q.front();
      q.pop();
      for (auto e : {x - v, x + v}) {
        if (0 <= e && e <= m && !st.contains(e)) {
          st.insert(e);
          q.push(e);
        }
      }
    }
  }

  int maxx = -1;
  while (!q.empty()) {
    auto x = q.front();
    q.pop();
    if (maxx < x) maxx = x;
  }
  cout << maxx;

  return 0;
}
