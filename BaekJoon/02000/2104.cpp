// Title : 부분배열 고르기
// Link  : https://www.acmicpc.net/problem/2104 
// Time  : 20 ms
// Memory: 4508 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  int64_t maxx = -1;
  vector<int64_t> sum(n + 2);
  vector<int> minn(n + 2);
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    minn[i] = sum[i] = x;
    int64_t cur = (int64_t)x * x;
    if (maxx < cur) maxx = cur;
  }

  vector<int> memo(n + 2), sz(n + 2, 1);
  iota(memo.begin(), memo.end(), 0);

  vector<bool> used(n + 2);

  auto Find = [&](int id) {
    while (id != memo[id]) {
      int par = memo[id];
      id = memo[id] = memo[par];
    }
    return id;
  };

  auto Union = [&](int a, int b) {
    a = Find(a), b = Find(b);
    if (a == b) return;
    if (a > b) swap(a, b);
    memo[b] = a;
    sz[a] += sz[b];
    minn[a] = min<int>(minn[a], minn[b]);
    sum[a] += sum[b];
    int64_t cur = sum[a] * minn[a];
    if (maxx < cur) maxx = cur;
  };

  vector<int> cands(n);
  iota(cands.begin(), cands.end(), 1);
  sort(cands.begin(), cands.end(), [&](int lhs, int rhs) {
    return sum[lhs] > sum[rhs];
  });

  for (auto i : cands) {
    used[i] = true;
    if (used[i - 1]) Union(i, i - 1);
    if (used[i + 1]) Union(i, i + 1);
  }

  cout << maxx;

  return 0;
}