// Title : 양 구출 작전
// Link  : https://www.acmicpc.net/problem/16437 
// Time  : 32 ms
// Memory: 4224 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<int> par(n + 1), deg(n + 1);
  vector<int64_t> memo(n + 1);
  for (int i = 2; i <= n; i++) {
    char t;
    int a, p;
    cin >> t >> a >> p;
    par[i] = p;
    ++deg[p];
    memo[i] = (t == 'S' ? a : -a);
  }

  queue<int> q;
  for (int i = 1; i <= n; i++) {
    if (deg[i]) continue;
    q.push(i);
  }

  while (!q.empty()) {
    int cur = q.front();
    q.pop();

    int p = par[cur];
    if (p == 0) continue;

    memo[p] += max<int64_t>(memo[cur], 0);
    if (--deg[p] == 0) q.push(p);
  }
  cout << memo[1];

  return 0;
}
