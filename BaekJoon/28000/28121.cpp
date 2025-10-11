// Title : 산책과 쿼리
// Link  : https://www.acmicpc.net/problem/28121 
// Time  : 224 ms
// Memory: 6708 KB

#include <bits/stdc++.h>

using namespace std;

constexpr int kMax = 3e5;

int ans;
int memo[kMax + 1], color[kMax + 1], sz[kMax + 1], err[kMax + 1];

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
    if (err[pa]) {
      ans += sz[pa];
      sz[pa] = 0;
    }
    return;
  }

  memo[pb] = pa;
  color[pb] = ca ^ cb ^ t;
  sz[pa] += sz[pb];
  err[pa] |= err[pb];
  if (err[pa]) {
    ans += sz[pa];
    sz[pa] = 0;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, q;
  cin >> n >> q;

  for (int i = 1; i <= n; i++) {
    memo[i] = i;
    sz[i] = 1;
  }

  while (q--) {
    int a, b;
    cin >> a >> b;
    Union(a, b, 1);
    cout << ans << "\n";
  }

  return 0;
}