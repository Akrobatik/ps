// Title : 주식회사 승범이네
// Link  : https://www.acmicpc.net/problem/16404 
// Time  : 52 ms
// Memory: 12100 KB

#include <bits/stdc++.h>

using namespace std;

vector<int> edges[100001];
int in[100001], out[100001];
int idx;
int64_t tree[100001];

void Traverse(int cur) {
  in[cur] = ++idx;
  for (auto nxt : edges[cur]) Traverse(nxt);
  out[cur] = idx + 1;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  int root;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    if (x == -1) {
      root = i;
    } else {
      edges[x].push_back(i);
    }
  }

  Traverse(root);

  auto Update = [&](int i, int delta) {
    for (; i <= n; i += i & (-i)) tree[i] += delta;
  };

  auto Query = [&](int i) {
    int64_t res = 0;
    for (; i; i -= i & (-i)) res += tree[i];
    return res;
  };

  while (m--) {
    int cmd;
    cin >> cmd;
    if (cmd == 1) {
      int i, w;
      cin >> i >> w;
      Update(in[i], w);
      Update(out[i], -w);
    } else {
      int i;
      cin >> i;
      cout << Query(in[i]) << "\n";
    }
  }

  return 0;
}
