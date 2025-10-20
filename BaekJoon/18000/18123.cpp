// Title : 평행우주
// Link  : https://www.acmicpc.net/problem/18123 
// Time  : 316 ms
// Memory: 9908 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int64_t> arr(n);
  for (int i = 0; i < n; i++) {
    int m;
    cin >> m;

    vector<vector<int>> g(m + 1);
    for (int j = 1; j < m; j++) {
      int u, v;
      cin >> u >> v;
      g[u].push_back(v);
      g[v].push_back(u);
    }

    vector<int> val(m);
    [&](this auto&& self, int cur, int par) -> int {
      int maxx = 0, sum = 1;
      for (auto nxt : g[cur]) {
        if (nxt == par) continue;
        int cnt = self(nxt, cur);
        maxx = max<int>(maxx, cnt);
        sum += cnt;
      }
      val[cur] = max<int>(maxx, m - sum);
      return sum;
    }(0, -1);

    int minn = *min_element(val.begin(), val.end());
    vector<int> cent;
    for (int j = 0; j < m; j++) {
      if (val[j] == minn) cent.push_back(j);
    }

    int root = (cent.size() == 1 ? cent[0] : m);
    if (root == m) {
      g[m].push_back(cent[0]);
      g[m].push_back(cent[1]);
    }

    arr[i] = [&](this auto&& self, int cur, int par) -> int64_t {
      vector<int64_t> tmp;
      for (auto nxt : g[cur]) {
        if (nxt == par) continue;
        tmp.push_back(self(nxt, cur));
      }
      sort(tmp.begin(), tmp.end());

      int64_t res = (cur != m ? 1 : 0);
      for (auto e : tmp) {
        int bw = bit_width((uint64_t)e);
        res = (res << bw) | e;
      }
      if (cur != m) res <<= 1;
      return res;
    }(root, -1) | (root == m ? (1LL << 62) : 0);
  }

  sort(arr.begin(), arr.end());
  arr.erase(unique(arr.begin(), arr.end()), arr.end());
  cout << arr.size();

  return 0;
}