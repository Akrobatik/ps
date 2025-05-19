// Title : 트리 뒤집기
// Link  : https://www.acmicpc.net/problem/33873 
// Time  : 56 ms
// Memory: 16964 KB

#include <bits/stdc++.h>

using namespace std;

vector<array<int, 2>> arr, memo;
vector<int> edges[100000];

int Traverse(int cur, int par, int dir) {
  auto& res = memo[cur][dir];
  if (res != -1) return res;

  if (arr[cur][dir] == arr[cur][dir ^ 1]) {
    int org = 0, rev = 1;
    for (auto nxt : edges[cur]) {
      if (nxt == par) continue;
      org += Traverse(nxt, cur, dir);
    }
    dir ^= 1;
    for (auto nxt : edges[cur]) {
      if (nxt == par) continue;
      rev += Traverse(nxt, cur, dir);
    }
    return res = min<int>(org, rev);
  }

  int cnt = 0;
  if (arr[cur][dir] < arr[cur][dir ^ 1]) dir ^= 1, ++cnt;

  for (auto nxt : edges[cur]) {
    if (nxt == par) continue;
    cnt += Traverse(nxt, cur, dir);
  }
  return res = cnt;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  arr.resize(n);
  for (auto& e : arr) cin >> e[0];
  for (auto& e : arr) cin >> e[1];

  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    edges[u].push_back(v);
    edges[v].push_back(u);
  }

  int maxx = 0;
  for (int i = 0; i < n; i++) maxx += max<int>(arr[i][0], arr[i][1]);

  memo.resize(n, {-1, -1});
  cout << maxx << " " << Traverse(0, -1, 0);

  return 0;
}
