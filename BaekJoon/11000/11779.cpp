// Title : 최소비용 구하기 2
// Link  : https://www.acmicpc.net/problem/11779
// Time  : 28 ms
// Memory: 3720 KB

#include <bits/stdc++.h>

using namespace std;

int n;
vector<pair<int, int>> edges[1001];
int memo[1001];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int m, start, end;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    edges[a].push_back({b, c});
  }
  cin >> start >> end;
  for (int i = 1; i <= n; i++) {
    sort(edges[i].begin(), edges[i].end());
    edges[i].erase(unique(edges[i].begin(), edges[i].end(),
                          [](const pair<int, int>& rhs, const pair<int, int>& lhs) {
                            return rhs.first == lhs.first;
                          }),
                   edges[i].end());
  }

  using E = tuple<int, int, vector<int16_t>>;
  priority_queue<E, vector<E>, greater<E>> pq;
  pq.push({0, start, vector<int16_t>(1, start)});
  fill_n(memo, 1001, INT_MAX);
  memo[start] = 0;
  while (!pq.empty()) {
    auto [cost, pos, path] = pq.top();
    pq.pop();

    if (pos == end) {
      cout << cost << "\n"
           << path.size() << "\n";
      for (int16_t v : path) cout << v << " ";
      break;
    }

    for (auto& edge : edges[pos]) {
      auto [b, c] = edge;
      if (memo[b] > cost + c) {
        memo[b] = cost + c;
        vector<int16_t> pth(path);
        pth.push_back(b);
        pq.push({cost + c, b, pth});
      }
    }
  }

  return 0;
}
