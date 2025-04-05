// Title : 소수 쌍
// Link  : https://www.acmicpc.net/problem/1017
// Time  : 0 ms
// Memory: 2028 KB

#include <bits/stdc++.h>

using namespace std;

bool seive[2001];
bool visited[501];
int memo[501];
vector<vector<int>> edges;

bool Traverse(int id) {
  if (visited[id]) return false;
  visited[id] = true;
  for (auto nxt : edges[id]) {
    if (memo[nxt] == 0 || Traverse(memo[nxt])) {
      memo[nxt] = id;
      return true;
    }
  }
  return false;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  for (int i = 2; i <= 2000; i++) {
    if (seive[i]) continue;
    for (int j = i * i; j <= 2000; j += i) seive[j] = true;
  }

  int n, a0;
  cin >> n >> a0;
  vector<int> a, b;
  a.push_back(a0);
  for (int i = 1; i < n; i++) {
    int x;
    cin >> x;
    if ((x ^ a0) & 1) {
      b.push_back(x);
    } else {
      a.push_back(x);
    }
  }

  if (a.size() != b.size()) {
    cout << "-1";
    return 0;
  }
  sort(b.begin(), b.end());

  n >>= 1;
  edges.resize(n + 1);
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (!seive[a[i] + b[j]]) {
        edges[i + 1].push_back(j + 1);
      }
    }
  }

  bool none = true;
  edges[1].resize(1);
  for (int i = 0; i < n; i++) {
    if (!seive[a0 + b[i]]) {
      memset(memo, 0, sizeof(memo));
      edges[1][0] = i + 1;
      int cnt = 0;
      for (int j = 1; j <= n; j++) {
        memset(visited, 0, sizeof(visited));
        cnt += Traverse(j);
      }
      if (cnt == n) {
        none = false;
        cout << b[i] << " ";
      }
    }
  }
  if (none) cout << "-1";

  return 0;
}
