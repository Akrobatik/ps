// Title : 원수의 원수
// Link  : https://www.acmicpc.net/problem/23818 
// Time  : 52 ms
// Memory: 3192 KB

#include <bits/stdc++.h>

using namespace std;

constexpr int kMax = 1e5;

int memo[kMax + 1], color[kMax + 1], err[kMax + 1];

pair<int, int> Find(int id) {
  if (memo[id] == id) return {id, 0};
  auto [par, col] = Find(memo[id]);
  return {memo[id] = par, color[id] ^= col};
}

void Union(int a, int b, int t) {
  auto [pa, ca] = Find(a);
  auto [pb, cb] = Find(b);
  if (pa == pb) {
    if (ca ^ cb ^ t) err[pa] = 1;
    return;
  }
  memo[pb] = pa;
  color[pb] = ca ^ cb ^ t;
  err[pa] |= err[pb];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  iota(memo, memo + kMax + 1, 0);

  int n, m, k;
  cin >> n >> m >> k;

  while (m--) {
    int t, a, b;
    cin >> t >> a >> b;
    Union(a, b, t);
  }

  while (k--) {
    int a, b;
    cin >> a >> b;

    auto [ap, ac] = Find(a);
    auto [bp, bc] = Find(b);
    if (ap != bp) {
      cout << "Unknown\n";
    } else if (err[ap]) {
      cout << "Error\n";
    } else {
      cout << (ac == bc ? "Friend\n" : "Enemy\n");
    }
  }

  return 0;
}