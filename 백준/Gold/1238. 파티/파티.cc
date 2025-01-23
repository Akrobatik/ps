#include <bits/stdc++.h>

using namespace std;

int n;
int memo[1001][1001];
vector<pair<int, int>> edges[1001];

struct Comp {
  constexpr bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs) const {
    return lhs.second > rhs.second;
  }
};

void Traverse(int start, int end = 0) {
  priority_queue<pair<int, int>, vector<pair<int, int>>, Comp> pq;
  pq.push(make_pair(start, 0));
  int* memo_tmp = memo[start];
  while (!pq.empty()) {
    auto [pos, cost] = pq.top();
    pq.pop();

    if (end && end == pos) break;

    for (auto [b, c] : edges[pos]) {
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
  fill_n((int*)memo, 1001 * 1001, INT_MAX);
  for (int i = 1; i <= n; i++) memo[i][i] = 0;

  while (m--) {
    int a, b, c;
    cin >> a >> b >> c;
    edges[a].push_back(make_pair(b, c));
  }

  int ans = 0;
  Traverse(x);
  for (int i = 1; i <= n; i++) Traverse(i, x);
  for (int i = 1; i <= n; i++) ans = max<int>(ans, memo[i][x] + memo[x][i]);
  cout << ans << endl;

  return 0;
}
