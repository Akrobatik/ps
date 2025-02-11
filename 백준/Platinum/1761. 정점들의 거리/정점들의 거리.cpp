#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> edges[40001];
int memo[40001][3];
// parent dist depth

pair<int, vector<int>> bfs(int start) {
  vector<int> dist(40001, -1);
  queue<int> q;
  q.push(start);
  dist[start] = 0;
  int farthest = start;

  while (!q.empty()) {
    int node = q.front();
    q.pop();

    for (auto [neighbor, _] : edges[node]) {
      if (dist[neighbor] == -1) {
        dist[neighbor] = dist[node] + 1;
        q.push(neighbor);
        farthest = neighbor;
      }
    }
  }
  return {farthest, dist};
}

int find_min_height_roots() {
  auto [A, _] = bfs(1);
  auto [B, dist_from_A] = bfs(A);
  vector<int> path;
  int node = B;
  while (node != A) {
    path.push_back(node);
    for (auto [neighbor, _] : edges[node]) {
      if (dist_from_A[neighbor] == dist_from_A[node] - 1) {
        node = neighbor;
        break;
      }
    }
  }
  path.push_back(A);
  return path[path.size() / 2];
}

void Traverse(int cur, int parent, int depth) {
  for (auto [to, dist] : edges[cur]) {
    if (to == parent) {
      memo[cur][0] = parent;
      memo[cur][1] = dist;
      memo[cur][2] = depth;
    } else {
      Traverse(to, cur, depth + 1);
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  while (--n) {
    int a, b, c;
    cin >> a >> b >> c;
    edges[a].push_back({b, c});
    edges[b].push_back({a, c});
  }
  int roots = find_min_height_roots();
  Traverse(roots, 0, 0);

  cin >> n;
  while (n--) {
    int a, b;
    cin >> a >> b;
    if (memo[a][2] > memo[b][2]) swap(a, b);

    int d = 0;
    while (memo[a][2] != memo[b][2]) {
      d += memo[b][1];
      b = memo[b][0];
    }

    while (a != b) {
      d += memo[a][1] + memo[b][1];
      a = memo[a][0];
      b = memo[b][0];
    }

    cout << d << "\n";
  }

  return 0;
}
