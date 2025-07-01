// Title : 하이퍼 토마토
// Link  : https://www.acmicpc.net/problem/17114 
// Time  : 404 ms
// Memory: 2340 KB

#include <bits/stdc++.h>

using namespace std;

constexpr array<array<int, 11>, 22> kDelta = []() {
  array<array<int, 11>, 22> delta{};
  for (int i = 0; i < 22; i++) {
    int idx = i >> 1, v = ((i & 1) << 1) - 1;
    for (int j = 0; j < 11; j++) {
      delta[i][j] = (j == idx ? v : 0);
    }
  }
  return delta;
}();

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int dims[11] = {};
  int all = 1;
  for (auto& e : dims) cin >> e, all *= e;

  int base[11];
  for (int i = 0, d = 1; i < 11; d *= dims[i++]) {
    base[i] = d;
  }

  auto Check = [&](const array<int, 11>& coord) {
    for (int i = 0; i < 11; i++) {
      if (coord[i] < 0 || coord[i] >= dims[i]) return false;
    }
    return true;
  };

  auto GetCoord = [&](int id) -> array<int, 11> {
    array<int, 11> res{};
    for (int i = 10; i >= 0; i--) {
      int v = id / base[i];
      res[i] = v;
      id -= v * base[i];
    }
    return res;
  };

  auto GetId = [&](const array<int, 11>& coord) {
    int id = 0;
    for (int i = 0; i < 11; i++) {
      id += coord[i] * base[i];
    }
    return id;
  };

  vector<bool> memo(all);
  queue<int> q;
  int rem = 0;
  for (int i = 0; i < all; i++) {
    int x;
    cin >> x;
    if (x == 1) {
      memo[i] = true;
      q.push(i);
    } else if (x == 0) {
      ++rem;
    } else {
      memo[i] = true;
    }
  }

  int i;
  for (i = 0; rem && !q.empty(); i++) {
    int nq = q.size();
    while (nq--) {
      auto id = q.front();
      q.pop();

      auto coord = GetCoord(id);
      for (auto delta : kDelta) {
        auto crd = coord;
        for (int j = 0; j < 11; j++) crd[j] += delta[j];
        if (Check(crd)) {
          auto nxt = GetId(crd);
          if (memo[nxt]) continue;
          --rem;
          memo[nxt] = true;
          q.push(nxt);
        }
      }
    }
  }

  if (rem) {
    cout << "-1";
  } else {
    cout << i;
  }

  return 0;
}
