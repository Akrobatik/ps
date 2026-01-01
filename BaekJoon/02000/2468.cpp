// Title : 안전 영역
// Link  : https://www.acmicpc.net/problem/2468 
// Time  : 0 ms
// Memory: 2316 KB

#include <bits/stdc++.h>

using namespace std;

constexpr pair<int, int> kDelta[] = {
    {-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<pair<int, int>> cells[101];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int x;
      cin >> x;
      cells[x].push_back({i, j});
    }
  }

  vector<int8_t> in(n * n);
  vector<int> memo(n * n);
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

  int maxx = 0, cur = 0;
  for (int i = 100; i > 0; i--) {
    auto& arr = cells[i];
    cur += arr.size();
    for (auto [y, x] : arr) {
      int id = y * n + x;
      for (auto [dy, dx] : kDelta) {
        int yy = y + dy, xx = x + dx;
        if (0 <= yy && yy < n && 0 <= xx && xx < n) {
          int jd = yy * n + xx;
          if (in[jd]) cur -= Union(id, jd);
        }
      }
      in[id] = 1;
    }
    maxx = max<int>(cur, maxx);
  }
  cout << maxx;

  return 0;
}