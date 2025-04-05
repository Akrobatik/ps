// Title : 단지번호붙이기
// Link  : https://www.acmicpc.net/problem/2667
// Time  : 0 ms
// Memory: 2024 KB

#include <bits/stdc++.h>

using namespace std;

constexpr pair<int, int> kDelta[] = {
    {-1, 0},
    {1, 0},
    {0, -1},
    {0, 1}};

bool memo[25][25];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      char c;
      cin >> c;
      memo[i][j] = c == '0';
    }
  }

  priority_queue<int, vector<int>, greater<>> ans;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (memo[i][j]) continue;

      int cnt = 0;
      queue<pair<int, int>> q;
      memo[i][j] = true;
      q.push({i, j});
      while (!q.empty()) {
        auto [y, x] = q.front();
        q.pop();

        ++cnt;

        for (auto [dy, dx] : kDelta) {
          int yy = y + dy, xx = x + dx;
          if (0 <= yy && yy < n && 0 <= xx && xx < n && !memo[yy][xx]) {
            memo[yy][xx] = true;
            q.push({yy, xx});
          }
        }
      }
      ans.push(cnt);
    }
  }

  cout << ans.size() << "\n";
  while (!ans.empty()) {
    cout << ans.top() << "\n";
    ans.pop();
  }

  return 0;
}
