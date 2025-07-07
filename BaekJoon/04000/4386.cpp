// Title : 별자리 만들기
// Link  : https://www.acmicpc.net/problem/4386 
// Time  : 0 ms
// Memory: 2236 KB

#include <bits/stdc++.h>

using namespace std;

int Read() {
  double x;
  cin >> x;
  return x * 100;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<pair<int, int>> coords(n);
  for (int i = 0; i < n; i++) {
    int y = Read(), x = Read();
    coords[i] = {y, x};
  }

  vector<int> memo(n);
  iota(memo.begin(), memo.end(), 0);

  auto Find = [&](int id) {
    while (id != memo[id]) {
      int par = memo[id];
      id = memo[id] = memo[par];
    }
    return id;
  };

  auto Union = [&](int a, int b) {
    a = Find(a), b = Find(b);
    if (a == b) return false;
    memo[b] = a;
    return true;
  };

  vector<tuple<int64_t, int, int>> cands;
  cands.reserve(n * (n - 1) / 2);
  for (int i = 0; i < n; i++) {
    auto [iy, ix] = coords[i];
    for (int j = i + 1; j < n; j++) {
      auto [jy, jx] = coords[j];
      int64_t dy = iy - jy, dx = ix - jx;
      cands.push_back({dy * dy + dx * dx, i, j});
    }
  }
  sort(cands.begin(), cands.end());

  int rem = n - 1;
  long double sum = 0.0L;
  for (int i = 0; rem > 0; i++) {
    auto [d, a, b] = cands[i];
    if (Union(a, b)) {
      --rem;
      sum += sqrt((long double)d) / 100.0L;
    }
  }
  cout << setprecision(2) << fixed << sum;

  return 0;
}
