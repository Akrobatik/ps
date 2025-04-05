// Title : 특정 거리의 도시 찾기
// Link  : https://www.acmicpc.net/problem/18352
// Time  : 332 ms
// Memory: 21608 KB

#include <bits/stdc++.h>

using namespace std;

bool visited[300001];
vector<int> edges[300001];
int ans[300000];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, k, x;
  cin >> n >> m >> k >> x;
  while (m--) {
    int a, b;
    cin >> a >> b;
    edges[a].push_back(b);
  }

  auto ae = ans;
  queue<pair<int, int>> q;
  visited[x] = true;
  q.push({x, 0});
  while (!q.empty()) {
    auto [i, w] = q.front();
    q.pop();

    if (w == k) {
      *ae++ = i;
      continue;
    }

    for (auto to : edges[i]) {
      if (visited[to]) continue;
      visited[to] = true;
      q.push({to, w + 1});
    }
  }

  if (ans == ae) {
    cout << "-1";
  } else {
    sort(ans, ae);
    for (auto ptr = ans; ptr != ae; ++ptr) cout << *ptr << "\n";
  }

  return 0;
}
