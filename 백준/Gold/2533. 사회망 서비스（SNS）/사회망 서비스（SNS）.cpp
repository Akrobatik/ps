#include <bits/stdc++.h>

using namespace std;

int ans;
vector<int> edges[1000001];
bool visited[1000001];

bool Traverse(int id) {
  visited[id] = true;

  bool needed = false;
  for (auto next : edges[id]) {
    if (visited[next]) continue;
    if (!Traverse(next)) {
      needed = true;
    }
  }

  if (needed) {
    ++ans;
    return true;
  }
  return false;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    edges[u].push_back(v);
    edges[v].push_back(u);
  }

  Traverse(1);
  cout << ans;

  return 0;
}
