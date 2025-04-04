// Title : 도시 분할 계획
// Link  : https://www.acmicpc.net/problem/1647
// Time  : 292 ms
// Memory: 14136 KB

#include <bits/stdc++.h>

using namespace std;

int nv, ne;
vector<tuple<int, int, int>> edges;
int memo[100001];

int GetParent(int a, int& depth) {
  depth++;
  if (memo[a] == a) return a;
  return memo[a] = GetParent(memo[a], depth);
}

bool Union(int a, int b) {
  int da = 0, db = 0;
  int pa = GetParent(a, da);
  int pb = GetParent(b, db);
  if (pa == pb) return false;
  if (da > db) {
    memo[pb] = pa;
  } else {
    memo[pa] = pb;
  }
  return true;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> nv >> ne;
  edges.resize(ne);
  for (int i = 0; i < ne; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    edges[i] = {c, a, b};
  }
  sort(edges.begin(), edges.end(), [](const tuple<int, int, int>& lhs, const tuple<int, int, int>& rhs) {
    return get<0>(lhs) < get<0>(rhs);
  });

  int ans = 0;
  auto it = edges.begin();
  for (int i = 1; i <= nv; i++) memo[i] = i;
  int maxx = INT_MIN;
  for (int i = 1; i < nv; i++) {
    for (;;) {
      auto [c, a, b] = *(it++);
      if (Union(a, b)) {
        ans += c;
        maxx = max<int>(maxx, c);
        break;
      }
    }
  }

  cout << ans - maxx << endl;

  return 0;
}
