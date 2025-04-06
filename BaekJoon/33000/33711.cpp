// Title : 내 이름 나무
// Link  : https://www.acmicpc.net/problem/33711 
// Time  : 416 ms
// Memory: 5696 KB

#include <bits/stdc++.h>

using namespace std;

pair<int, int> memo[35001];
bool visited[35001];
vector<int> groups[35000];
vector<int> edges[35001];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, k, w;
  cin >> n >> m >> k >> w;

  unordered_map<string, int> hm;
  while (w--) {
    int x;
    string s;
    cin >> x >> s;
    if (auto it = hm.find(s); it != hm.end()) {
      groups[it->second].push_back(x);
    } else {
      groups[hm[s] = hm.size()].push_back(x);
    }
  }
  while (m--) {
    int u, v;
    cin >> u >> v;
    edges[u].push_back(v);
    edges[v].push_back(u);
  }

  int ns = hm.size();
  for (int i = 0; i < ns; i++) {
    if (groups[i].size() == 1) continue;

    memset(visited + 1, 0, n);

    queue<int> q;
    for (auto x : groups[i]) {
      memo[x] = {x, 0};
      visited[x] = true;
      q.push(x);
    }

    for (int j = 1; !q.empty() && j <= ((k + 1) >> 1); j++) {
      int nq = q.size();
      while (nq--) {
        int cur = q.front();
        q.pop();

        auto [cp, cd] = memo[cur];
        for (auto nxt : edges[cur]) {
          if (visited[nxt]) {
            auto [np, nd] = memo[nxt];
            if (cp != np && cd + nd < k) {
              cout << "POWERFUL CODING JungHwan";
              return 0;
            }
          } else {
            memo[nxt] = {cp, j};
            visited[nxt] = true;
            q.push(nxt);
          }
        }
      }
    }
  }
  cout << "so sad";

  return 0;
}
