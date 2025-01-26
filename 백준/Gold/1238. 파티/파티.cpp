#include <bits/stdc++.h>

using namespace std;

int n;
int memo[2][1001];
vector<pair<int, int>> edges[2][1001];

struct Comp {
  constexpr bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs) const {
    return lhs.second > rhs.second;
  }
};

void Traverse(int start, int direction) {
  auto* memo_tmp = memo[direction];
  auto* edge_tmp = edges[direction];
  fill_n(memo_tmp + 1, n, INT_MAX);
  memo_tmp[start] = 0;
  priority_queue<pair<int, int>, vector<pair<int, int>>, Comp> pq;
  pq.push(make_pair(start, 0));
  while (!pq.empty()) {
    auto [pos, cost] = pq.top();
    pq.pop();

    for (auto [b, c] : edge_tmp[pos]) {
      if (memo_tmp[b] > cost + c) {
        memo_tmp[b] = cost + c;
        pq.push(make_pair(b, cost + c));
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int m, x;
  cin >> n >> m >> x;

  while (m--) {
    int a, b, c;
    cin >> a >> b >> c;
    edges[0][a].push_back(make_pair(b, c));
    edges[1][b].push_back(make_pair(a, c));
  }

  int ans = 0;
  Traverse(x, 0);
  Traverse(x, 1);
  for (int i = 1; i <= n; i++) ans = max<int>(ans, memo[0][i] + memo[1][i]);
  cout << ans << endl;

  return 0;
}
