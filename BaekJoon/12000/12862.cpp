// Title : Love Triangles
// Link  : https://www.acmicpc.net/problem/12862 
// Time  : 28 ms
// Memory: 4340 KB

#include <bits/stdc++.h>

using namespace std;

constexpr int kMod = 1e9 + 7;

int memo[100001], color[100001];

pair<int, int> Find(int id) {
  if (memo[id] == id) return {id, 0};
  auto [par, col] = Find(memo[id]);
  memo[id] = par, color[id] ^= col;
  return {memo[id], color[id]};
}

void UnionO(int a, int b) {
  a = Find(a).first, b = Find(b).first;
  memo[b] = a;
}

bool UnionX(int a, int b) {
  auto [pa, ca] = Find(a);
  auto [pb, cb] = Find(b);
  if (pa == pb) return ca != cb;
  memo[pb] = pa;
  color[pb] = ca ^ cb ^ 1;
  return true;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  iota(memo, memo + n + 1, 0);

  vector<pair<int, int>> arr, brr;
  while (m--) {
    int a, b, c;
    cin >> a >> b >> c;
    if (c == 1) {
      arr.push_back({a, b});
    } else {
      brr.push_back({a, b});
    }
  }

  for (auto [a, b] : arr) {
    UnionO(a, b);
  }
  for (auto [a, b] : brr) {
    if (!UnionX(a, b)) {
      cout << "0";
      return 0;
    }
  }

  int cnt = -1;
  for (int i = 1; i <= n; i++) {
    cnt += (memo[i] == i);
  }

  int64_t r = 1, p = 2;
  while (cnt) {
    if (cnt & 1) r = r * p % kMod;
    p = p * p % kMod;
    cnt >>= 1;
  }
  cout << r;

  return 0;
}