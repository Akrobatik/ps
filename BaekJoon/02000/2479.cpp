// Title : 경로 찾기
// Link  : https://www.acmicpc.net/problem/2479 
// Time  : 0 ms
// Memory: 2176 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;

  vector<int> arr(n + 1);
  for (int i = 1; i <= n; i++) {
    string s;
    cin >> s;
    arr[i] = stoi(s, 0, 2);
  }

  vector<vector<int>> g(n + 1);
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      int x = arr[i] ^ arr[j];
      if (has_single_bit((uint32_t)x)) {
        g[i].push_back(j);
        g[j].push_back(i);
      }
    }
  }

  vector<int> par(n + 1, -1);
  queue<int> q;

  auto Push = [&](int x, int p) {
    if (par[x] != -1) return;
    par[x] = p;
    q.push(x);
  };

  int a, b;
  cin >> a >> b;

  Push(a, 0);
  while (!q.empty()) {
    int cur = q.front();
    q.pop();

    for (auto nxt : g[cur]) {
      Push(nxt, cur);
    }
  }

  int cur = b;
  vector<int> ans;
  while (cur) {
    ans.push_back(cur);
    cur = par[cur];
  }

  for (auto e : views::reverse(ans)) cout << e << " ";

  return 0;
}