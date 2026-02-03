// Title : Joust Sort
// Link  : https://www.acmicpc.net/problem/35248 
// Time  : 0 ms
// Memory: 2164 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<int> deg(256);
  vector<vector<int>> g(256);
  while (n--) {
    char u, v, dir;
    cin >> u >> dir >> v;
    if (dir == '>') swap(u, v);

    g[u].push_back(v);
    ++deg[v];
  }

  string s;
  cin >> s;

  int cnt[256] = {};
  for (auto c : s) ++cnt[c];

  queue<int> q;
  for (int i = 'a'; i <= 'z'; i++) {
    if (deg[i] == 0) q.push(i);
  }

  string ans;
  while (!q.empty()) {
    int cur = q.front();
    q.pop();

    while (cnt[cur]--) ans.push_back(cur);
    for (auto nxt : g[cur]) {
      if (--deg[nxt] == 0) q.push(nxt);
    }
  }

  cout << (s.size() == ans.size() ? ans : "IMPOSSIBLE");

  return 0;
}