// Title : 회사 문화 2
// Link  : https://www.acmicpc.net/problem/14268 
// Time  : 40 ms
// Memory: 11188 KB

#include <bits/stdc++.h>

using namespace std;

vector<int> edges[100001];
int in[100001], out[100001];
int idx;

void Traverse(int cur) {
  in[cur] = ++idx;
  for (auto nxt : edges[cur]) {
    Traverse(nxt);
  }
  out[cur] = idx;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, x;
  cin >> n >> m >> x;
  for (int i = 2; i <= n; i++) {
    cin >> x;
    edges[x].push_back(i);
  }

  Traverse(1);

  vector<int> tree(n + 1);

  auto Update = [&](int i, int v) {
    for (; i <= n; i += i & (-i)) tree[i] += v;
  };

  auto Query = [&](int i) {
    int res = 0;
    for (; i > 0; i -= i & (-i)) res += tree[i];
    return res;
  };

  while (m--) {
    int cmd;
    cin >> cmd;
    if (cmd == 1) {
      int i, w;
      cin >> i >> w;
      Update(in[i], w);
      Update(out[i] + 1, -w);
    } else {
      int i;
      cin >> i;
      cout << Query(in[i]) << "\n";
    }
  }

  return 0;
}
