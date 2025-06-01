// Title : 격자판 채우기
// Link  : https://www.acmicpc.net/problem/1648 
// Time  : 16 ms
// Memory: 3992 KB

#include <bits/stdc++.h>

using namespace std;

constexpr int kMod = 9901;

using tup = tuple<int, int, int>;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  if ((n * m) & 1) {
    cout << "0";
    return 0;
  }

  if (n > m) swap(n, m);
  int sz = 1 << n;

  vector<vector<int>> table(sz);
  queue<tup> q;
  for (int i = 0; i < sz; i++) {
    q.push({i, 0, 0});
    while (!q.empty()) {
      auto [c, r, nxt] = q.front();
      q.pop();

      if (r == n) {
        table[i].push_back(nxt);
        continue;
      }

      if (c & (1 << r)) {
        q.push({c, r + 1, nxt});
      } else {
        if (r + 1 < n && !(c & (2 << r))) {
          q.push({c | (3 << r), r + 2, nxt});
        }
        q.push({c | (1 << r), r + 1, nxt | (1 << r)});
      }
    }
  }

  vector<int> memo(sz), mnxt(sz);
  memo[0] = 1;
  for (int i = 0; i < m; i++) {
    fill(mnxt.begin(), mnxt.end(), 0);
    for (int j = 0; j < sz; j++) {
      if (memo[j] == 0) continue;
      for (auto nxt : table[j]) {
        mnxt[nxt] += memo[j];
        if (mnxt[nxt] >= kMod) mnxt[nxt] -= kMod;
      }
    }
    swap(memo, mnxt);
  }
  cout << memo[0] % kMod;

  return 0;
}
