// Title : Build Dependencies
// Link  : https://www.acmicpc.net/problem/35070 
// Time  : 304 ms
// Memory: 32228 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  unordered_map<string, int> hm;
  vector<string> keys(n), lines(n);
  for (int i = 0; i < n; i++) {
    cin >> ws;
    getline(cin, lines[i]);

    istringstream iss(lines[i]);
    iss >> keys[i];
    keys[i].pop_back();
    hm[keys[i]] = i;
  }

  vector<vector<int>> g(n);
  for (int i = 0; i < n; i++) {
    istringstream iss(lines[i]);
    string s;
    iss >> s;
    while (iss >> s) {
      int x = hm[s];
      g[x].push_back(i);
    }
  }

  queue<int> q;
  vector<int8_t> vis(n);
  vector<int> deg(n);

  auto Push = [&](int x) {
    ++deg[x];
    if (vis[x]) return;
    vis[x] = 1;
    q.push(x);
  };

  string s;
  cin >> s;
  Push(hm[s]);
  while (!q.empty()) {
    int cur = q.front();
    q.pop();

    for (auto nxt : g[cur]) {
      Push(nxt);
    }
  }

  q.push(hm[s]);
  while (!q.empty()) {
    int cur = q.front();
    q.pop();

    cout << keys[cur] << "\n";

    for (auto nxt : g[cur]) {
      if (--deg[nxt] == 0) {
        q.push(nxt);
      }
    }
  }

  return 0;
}