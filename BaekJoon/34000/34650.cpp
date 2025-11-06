// Title : Conflict
// Link  : https://www.acmicpc.net/problem/34650 
// Time  : 724 ms
// Memory: 14736 KB

#include <bits/stdc++.h>

using namespace std;

void Query(int st, int n, vector<int>& out) {
  cout << "?";
  for (int i = 0; i < n; i++) {
    cout << " " << (i + n - st) % n + 1;
  }
  cout << endl;

  out.resize(n + 1);
  for (int i = 0; i < n; i++) {
    int x = (i + n - st) % n + 1;
    cin >> out[x];
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<vector<int>> res;
  vector<pair<int, int>> ans;

  auto Push = [&](int u, int v, int cnt) {
    while (cnt--) ans.push_back({u, v});
  };

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    res.resize(n);

    for (int i = 0; i + 1 < n; i++) Query(i, n, res[i]);
    res[n - 1].assign(n + 1, 0);

    for (int i = 1; i < n; i++) {
      for (int j = 0; j + i < n; j++) {
        int u = i, v = n - j;
        Push(i, n - j, res[j][i] - res[j + 1][i]);
      }
    }

    cout << "! " << ans.size() << "\n";
    for (auto [u, v] : ans) cout << u << " " << v << "\n";
    cout << flush;

    ans.clear();
  }

  return 0;
}