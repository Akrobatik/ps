// Title : 가오리 그래프
// Link  : https://www.acmicpc.net/problem/33888 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int ans[6];
vector<int> edges[51];
vector<int> check;
vector<int> check2;
bool visited[51];

void E(int cur) {
  for (auto x : check2) {
    if (x == cur) {
      if (ans[4] != cur) swap(ans[2], ans[4]);
      return;
    }
  }

  visited[cur] = true;
  for (auto nxt : edges[cur]) {
    if (visited[nxt]) continue;
    E(nxt);
  }
}

void BD(int cur) {
  for (auto x : check) {
    if (x == cur) {
      if (ans[1] == 0) {
        ans[1] = cur;
      } else {
        ans[3] = cur;
      }
      return;
    }
  }

  visited[cur] = true;
  for (auto nxt : edges[cur]) {
    if (visited[nxt]) continue;
    BD(nxt);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  for (int i = 0; i < n + 3; i++) {
    int u, v;
    cin >> u >> v;
    edges[u].push_back(v);
    edges[v].push_back(u);
  }

  for (int i = 1; i <= n; i++) {
    if (edges[i].size() == 1) ans[5] = i;
    if (edges[i].size() == 4) {
      check2.push_back(i);
      if (ans[2] == 0) {
        ans[2] = i;
      } else {
        ans[4] = i;
      }
    }
    if (edges[i].size() == 3) check.push_back(i);
  }

  E(ans[5]);
  visited[ans[2]] = true;
  BD(ans[4]);

  for (auto& e : check) {
    for (auto x : ans) {
      if (e == x) e = 0;
    }
    ans[0] = max<int>(ans[0], e);
  }

  if (ans[1] > ans[3]) swap(ans[1], ans[3]);

  for (auto e : ans) cout << e << " ";

  return 0;
}
