#include <bits/stdc++.h>

using namespace std;

int memo[100000];
pair<int, int> xs[100000];
pair<int, int> ys[100000];
pair<int, int> zs[100000];
tuple<int, int, int> ds[300000 - 3];

int Find(int id, int& depth) {
  while (id != memo[id]) {
    int parent = memo[id];
    memo[id] = memo[parent];
    id = parent;
    ++depth;
  }
  return id;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> xs[i].first >> ys[i].first >> zs[i].first;
    xs[i].second = ys[i].second = zs[i].second = i;
    memo[i] = i;
  }
  sort(xs, xs + n);
  sort(ys, ys + n);
  sort(zs, zs + n);

  int nn = n * 3 - 3;
  auto p = ds;
  for (int i = 0; i < n - 1; i++) {
    *p++ = {xs[i + 1].first - xs[i].first, xs[i].second, xs[i + 1].second};
    *p++ = {ys[i + 1].first - ys[i].first, ys[i].second, ys[i + 1].second};
    *p++ = {zs[i + 1].first - zs[i].first, zs[i].second, zs[i + 1].second};
  }
  sort(ds, ds + nn);

  int64_t sum = 0;
  for (int i = 0; i < nn; i++) {
    auto [d, a, b] = ds[i];
    int da = 0, db = 0;
    int pa = Find(a, da);
    int pb = Find(b, db);
    if (pa == pb) continue;
    if (da < db) swap(pa, pb);
    memo[pb] = pa;
    sum += d;
  }

  cout << sum;

  return 0;
}
