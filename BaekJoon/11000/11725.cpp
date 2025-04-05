// Title : 트리의 부모 찾기
// Link  : https://www.acmicpc.net/problem/11725
// Time  : 40 ms
// Memory: 8060 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<vector<int>> vec(n + 1, vector<int>());
  for (int i = 1; i < n; i++) {
    int x, y;
    cin >> x >> y;
    vec[x].push_back(y);
    vec[y].push_back(x);
  }

  vector<int> ans(n + 1, 0);
  ans[1] = 1;

  queue<int> q;
  q.push(1);
  while (!q.empty()) {
    int v = q.front();
    q.pop();

    const auto& nexts = vec[v];
    for (auto next : nexts) {
      if (ans[next] == 0) {
        ans[next] = v;
        q.push(next);
      }
    }
  }

  for (int i = 2; i <= n; i++) {
    cout << ans[i] << "\n";
  }

  return 0;
}
