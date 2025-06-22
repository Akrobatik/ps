// Title : 점프 게임
// Link  : https://www.acmicpc.net/problem/15558 
// Time  : 4 ms
// Memory: 2552 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  string s[2];
  cin >> n >> k >> s[0] >> s[1];

  queue<pair<int, int>> q;
  vector<bool> visited[2];
  for (auto& e : visited) e.resize(n);

  auto Push = [&](int i, int j) {
    if (s[i][j] != '1' || visited[i][j]) return;
    visited[i][j] = true;
    q.push({i, j});
  };

  Push(0, 0);

  bool ok = false;
  for (int i = 0; !q.empty() && !ok; i++) {
    int nq = q.size();
    while (nq--) {
      auto [lr, pos] = q.front();
      q.pop();

      if (pos + k >= n) {
        ok = true;
        break;
      }

      Push(lr, pos + 1);
      Push(lr ^ 1, pos + k);
      if (pos - 1 > i) Push(lr, pos - 1);
    }
  }
  cout << ok;

  return 0;
}
