// Title : 수상한 문자열
// Link  : https://www.acmicpc.net/problem/34897 
// Time  : 4 ms
// Memory: 3584 KB

#include <bits/stdc++.h>

using namespace std;

constexpr int kMax = 2e5;

int memo[kMax + 1], color[kMax + 1];

pair<int, int> Find(int id) {
  if (memo[id] == id) return {id, 0};
  auto [par, col] = Find(memo[id]);
  return {memo[id] = par, color[id] ^= col};
}

bool Union(int a, int b, int t) {
  auto [pa, ca] = Find(a);
  auto [pb, cb] = Find(b);
  if (pa == pb) {
    if (ca ^ cb ^ t) return false;
    return true;
  }

  memo[pb] = pa;
  color[pb] = ca ^ cb ^ t;
  return true;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  iota(memo, memo + n + 1, 0);

  while (m--) {
    int cmd, i, j;
    cin >> cmd >> i >> j;
    if (cmd == 1) {
      while (i < j) {
        if (!Union(i, j, 0)) {
          cout << "No";
          return 0;
        }
        ++i, --j;
      }
    } else {
      if (!Union(i, j, 1)) {
        cout << "No";
        return 0;
      }
    }
  }

  cout << "Yes\n";
  for (int i = 1; i <= n; i++) {
    auto [pi, ci] = Find(i);
    cout << (ci ? 'A' : 'B');
  }

  return 0;
}