// Title : 원숭이도 나무에서 떨어진다
// Link  : https://www.acmicpc.net/problem/33872 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

vector<int> arr, brr, edges[25];
int visited[25];
int maxx;

void Traverse(int cur, int dst, int rem, int sum) {
  if (visited[cur] == 0) sum += arr[cur];

  if (rem == 0) {
    if (cur == dst) maxx = max<int>(maxx, sum);
    return;
  }

  ++visited[cur];
  for (auto nxt : edges[cur]) {
    if (brr[nxt] || visited[nxt] == 2) continue;
    Traverse(nxt, dst, rem - 1, sum);
  }
  --visited[cur];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, h, s, e;
  cin >> n >> h >> s >> e;
  --s, --e;
  arr.resize(n), brr.resize(n);
  for (auto& e : arr) cin >> e;
  for (auto& e : brr) cin >> e;

  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    edges[u].push_back(v);
    edges[v].push_back(u);
  }

  maxx = -1;
  Traverse(s, e, h, 0);
  cout << maxx;

  return 0;
}
