#include <bits/stdc++.h>

using namespace std;

vector<int> edges[100001];
int memo[100001];
bool visited[100001];

int GetSubtreeVertexs(int id) {
  if (visited[id]) return 0;
  visited[id] = true;

  auto& cur_edges = edges[id];
  if (cur_edges.empty()) {
    memo[id] = 1;
    return 1;
  }

  int cnt = 1;
  for (auto child_id : cur_edges) {
    if (!visited[child_id]) cnt += GetSubtreeVertexs(child_id);
  }
  memo[id] = cnt;
  return cnt;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, r, q;
  cin >> n >> r >> q;
  for (int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
    edges[a].push_back(b);
    edges[b].push_back(a);
  }

  GetSubtreeVertexs(r);

  for (int i = 0; i < q; i++) {
    int v;
    cin >> v;
    cout << memo[v] << "\n";
  }

  return 0;
}
