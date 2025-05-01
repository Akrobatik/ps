// Title : 팰린드롬
// Link  : https://www.acmicpc.net/problem/5502 
// Time  : 172 ms
// Memory: 26572 KB

#include <bits/stdc++.h>

using namespace std;

bool visited[5000][5000];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  string s;
  cin >> n >> s;

  queue<pair<int, int>> q;

  auto Push = [&](int l, int r) {
    while (l < r && s[l] == s[r]) ++l, --r;
    if (visited[l][r]) return;
    visited[l][r] = true;
    q.push({l, r});
  };

  Push(0, n - 1);

  for (int i = 0; !q.empty(); i++) {
    int nq = q.size();
    while (nq--) {
      auto [l, r] = q.front();
      q.pop();

      if (l >= r) {
        cout << i;
        return 0;
      }

      Push(l + 1, r);
      Push(l, r - 1);
    }
  }

  return 0;
}
