// Title : 금오리 🦆
// Link  : https://www.acmicpc.net/problem/34330 
// Time  : 0 ms
// Memory: 2024 KB

#include <bits/stdc++.h>

using namespace std;

using tup = tuple<int64_t, int64_t, int64_t>;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int64_t sr, sl, n, m;
  cin >> sr >> sl >> n >> m;

  vector<tup> arr(n);
  for (auto& [x, y, r] : arr) cin >> x >> y >> r;

  vector<bool> act(n);
  for (int i = 0; i < n; i++) {
    auto [x, y, r] = arr[i];
    int64_t vr = sr - r;
    int64_t vd = x * x + y * y;
    act[i] = (vr <= 0 || vr * vr <= vd);
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
    if (a == b) return;
		if (!act[a]) swap(a, b);
    memo[b] = a;
  };

  for (int i = 0; i < n; i++) {
    auto [ix, iy, ir] = arr[i];
    for (int j = i + 1; j < n; j++) {
      auto [jx, jy, jr] = arr[j];
      int64_t dx = ix - jx, dy = iy - jy;
      int64_t dr = ir + jr;
      if (dr * dr >= dx * dx + dy * dy) {
        Union(i, j);
      }
    }
  }

  vector<int> ids;
  for (int i = 0; i < n; i++) {
		int id = Find(i);
		if (act[id]) ids.push_back(i);
	}

  int cnt = 0;
  while (m--) {
    int64_t x, y;
    cin >> x >> y;

    int64_t vr = sr - sl;
    int64_t vd = x * x + y * y;
    if (vr <= 0 || vr * vr <= vd) {
      ++cnt;
    } else {
      for (auto id : ids) {
        auto [xx, yy, rr] = arr[id];
        int64_t dx = x - xx, dy = y - yy;
        int64_t dr = sl + rr;
        if (dr * dr >= dx * dx + dy * dy) {
          ++cnt;
          break;
        }
      }
    }
  }
  cout << cnt;

  return 0;
}
