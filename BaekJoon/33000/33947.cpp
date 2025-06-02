// Title : 특별한 정점
// Link  : https://www.acmicpc.net/problem/33947 
// Time  : 120 ms
// Memory: 22860 KB

#include <bits/stdc++.h>

using namespace std;

vector<int> edges[200001];
bool check[200001];
int ans;

bool Traverse(int cur, int par) {
  int cnt = 0;
  for (auto nxt : edges[cur]) {
    if (nxt == par) continue;
    cnt += Traverse(nxt, cur);
  }

  if (cnt > 1) {
    ans += cnt - 1;
    return false;
  }
  return (cnt + check[cur] != 0);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  for (int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
    edges[a].push_back(b);
    edges[b].push_back(a);
  }

  int root = 0;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    if (x) check[i] = true, root = i;
  }

  if (root == 0) {
    cout << "0";
    return 0;
  }

  if (Traverse(root, 0)) ++ans;
  cout << max<int>(ans - 1, 0);

  return 0;
}
