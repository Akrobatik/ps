#include <bits/stdc++.h>

using namespace std;

vector<int> edges[10001];
int cnts[10001];
int parents[10001], depths[10001];

void Traverse(int cur, int par, int depth) {
  depths[cur] = depth;
  parents[cur] = par;

  for (auto nxt : edges[cur]) {
    Traverse(nxt, cur, depth + 1);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    memset(cnts + 1, 0, n * sizeof(int));
    memset(parents + 1, 0, n * sizeof(int));
    memset(depths + 1, 0, n * sizeof(int));
    for (int i = 1; i <= n; i++) edges[i].clear();

    for (int i = 1; i < n; i++) {
      int a, b;
      cin >> a >> b;
      edges[a].push_back(b);
      ++cnts[b];
    }

    int r;
    for (int i = 1; i <= n; i++) {
      if (cnts[i]) continue;
      r = i;
      break;
    }

    Traverse(r, 0, 0);

    int a, b;
    cin >> a >> b;
    if (depths[a] > depths[b]) swap(a, b);
    int delta = depths[b] - depths[a];
    for (int i = 0; i < delta; i++) b = parents[b];

    while (a != b) {
      a = parents[a], b = parents[b];
    }
    cout << a << "\n";
  }

  return 0;
}
