// Title : 왕위 계승
// Link  : https://www.acmicpc.net/problem/5021 
// Time  : 0 ms
// Memory: 2036 KB

#include <bits/stdc++.h>

using namespace std;

int deg[151];
int64_t memo[151];
vector<int> edges[151];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  unordered_map<string, int> hm;

  string s;
  int n, m;
  cin >> n >> m >> s;
  hm[s] = 0;
  memo[0] = 1ll << 60;
  for (int i = 0; i < n; i++) {
    string cn, fn, mn;
    cin >> cn >> fn >> mn;
    if (!hm.contains(cn)) hm[cn] = hm.size();
    if (!hm.contains(fn)) hm[fn] = hm.size();
    if (!hm.contains(mn)) hm[mn] = hm.size();
    edges[hm[fn]].push_back(hm[cn]);
    edges[hm[mn]].push_back(hm[cn]);
    deg[hm[cn]] = 2;
  }

  queue<int> q;
  for (int i = 0; i < hm.size(); i++) {
    if (deg[i]) continue;
    q.push(i);
  }

  while (!q.empty()) {
    int cur = q.front();
    q.pop();

    for (auto nxt : edges[cur]) {
      memo[nxt] += (memo[cur] >> 1);
      if (--deg[nxt] == 0) {
        q.push(nxt);
      }
    }
  }

  string ans;
  int64_t maxx = -1;
  for (int i = 0; i < m; i++) {
    string cn;
    cin >> cn;
    int ci = hm[cn];
    if (ci == 0) continue;
    if (maxx < memo[ci]) maxx = memo[ci], ans = cn;
  }
  cout << ans;

  return 0;
}
