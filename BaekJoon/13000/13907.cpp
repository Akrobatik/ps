// Title : 세금
// Link  : https://www.acmicpc.net/problem/13907 
// Time  : 1344 ms
// Memory: 25336 KB

#include <bits/stdc++.h>

using namespace std;

using tup = tuple<int, int, int>;

vector<pair<int, int>> edges[1001];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, k, s, d;
  cin >> n >> m >> k >> s >> d;
  while (m--) {
    int a, b, w;
    cin >> a >> b >> w;
    edges[a].push_back({b, w});
    edges[b].push_back({a, w});
  }

  vector<vector<int>> memo(n + 1, vector<int>(n, INT_MAX >> 1));
  priority_queue<tup, vector<tup>, greater<tup>> pq;

  auto Push = [&](int x, int c, int w) {
    if (c >= n || memo[x][c] <= w) return;
    memo[x][c] = w;
    pq.push({w, x, c});
  };

  Push(s, 0, 0);
  while (!pq.empty()) {
    auto [w, x, c] = pq.top();
    pq.pop();

    if (w != memo[x][c]) continue;

    for (auto [nxt, ww] : edges[x]) {
      Push(nxt, c + 1, w + ww);
    }
  }

  vector<pair<int, int>> arr;
  int minn = INT_MAX >> 1;
  for (int i = 0; i < n; i++) {
    if (minn <= memo[d][i]) continue;
    minn = memo[d][i];
    arr.push_back({i, minn});
  }

  int64_t add = 0;

  cout << arr.back().second << "\n";
  while (k--) {
    int x;
    cin >> x;
    add += x;
    int64_t minn = INT64_MAX, mi;
    for (int i = 0; i < arr.size(); i++) {
      int64_t cur = add * arr[i].first + arr[i].second;
      if (minn > cur) minn = cur, mi = i;
    }
    arr.resize(mi + 1);
    cout << minn << "\n";
  }

  return 0;
}
