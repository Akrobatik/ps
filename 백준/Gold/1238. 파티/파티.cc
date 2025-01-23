#include <bits/stdc++.h>

using namespace std;

int n;
int memo[1001][1001];
bool visited[1001];

struct Comp {
  constexpr bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs) const {
    return lhs.second > rhs.second;
  }
};

void Traverse(int start, int end = 0) {
  memset(visited, 0, sizeof(visited));
  priority_queue<pair<int, int>, vector<pair<int, int>>, Comp> pq;
  pq.push(make_pair(start, 0));
  bool first = true;
  while (!pq.empty()) {
    auto [pos, cost] = pq.top();
    pq.pop();

    if (end && end == pos) break;
    if (visited[pos]) continue;
    visited[pos] = true;

    for (int i = 1; i <= n; i++) {
      if (!visited[i] && memo[pos][i] != INT_MAX && (memo[start][i] > cost + memo[pos][i] || first)) {
        memo[start][i] = cost + memo[pos][i];
        pq.push(make_pair(i, cost + memo[pos][i]));
      }
    }
    first = false;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int m, x;
  cin >> n >> m >> x;
  fill_n((int*)memo, 1001 * 1001, INT_MAX);
  for (int i = 1; i <= n; i++) memo[i][i] = 0;

  while (m--) {
    int a, b, c;
    cin >> a >> b >> c;
    memo[a][b] = c;
  }

  int ans = 0;
  Traverse(x);
  for (int i = 1; i <= n; i++) Traverse(i, x);
  for (int i = 1; i <= n; i++) ans = max<int>(ans, memo[i][x] + memo[x][i]);
  cout << ans << endl;

  return 0;
}
