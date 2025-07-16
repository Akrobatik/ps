// Title : 풍성한 트리
// Link  : https://www.acmicpc.net/problem/32934 
// Time  : 88 ms
// Memory: 14152 KB

#include <bits/stdc++.h>

using namespace std;

vector<int> edges[200001];
int maxx, root;

int Traverse(int cur, int par) {
  int arr[3] = {};
  for (auto nxt : edges[cur]) {
    if (nxt == par) continue;
    arr[2] = Traverse(nxt, cur);
    sort(arr, arr + 3, greater<int>());
  }
  int val = arr[0] + arr[1];
  if (maxx < val) maxx = val, root = cur;
  return arr[0] + 1;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    edges[u].push_back(v);
    edges[v].push_back(u);
  }

  int c1 = 0, c3 = 0;
  for (int i = 1; i <= n; i++) {
    int x = edges[i].size();
    c1 += (x == 1);
    c3 += (x == 3);
  }

  if (c1 + c3 != n) {
    cout << "-1";
    return 0;
  }

  Traverse(1, 0);
  if ((maxx & 1) || (1 << (maxx >> 1) - 1) * 3 != c1 || c1 != c3 + 2) {
    cout << "-1";
    return 0;
  }
  cout << "1\n"
       << root;

  return 0;
}
