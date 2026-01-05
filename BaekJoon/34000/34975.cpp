// Title : 그래플링 후크
// Link  : https://www.acmicpc.net/problem/34975 
// Time  : 136 ms
// Memory: 9180 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<pair<int, int>> yx(n);
  vector<int> dist(n);
  for (int i = 0; i < n; i++) {
    auto& [y, x] = yx[i];
    cin >> x >> y;
    dist[i] = abs(y) + abs(x);
  }

  vector<int> ids(n);
  iota(ids.begin(), ids.end(), 0);
  sort(ids.begin(), ids.end(), [&](int lhs, int rhs) {
    return dist[lhs] < dist[rhs];
  });

  map<int, int> mp;
  int idx = 0;
  while (idx < n) {
    int nxt = idx, val = dist[ids[idx]];
    while (nxt < n && val == dist[ids[nxt]]) ++nxt;

    mp[val] = nxt - idx;
    idx = nxt;
  }

  int m;
  cin >> m;
  while (m--) {
    int x;
    cin >> x;

    auto it = mp.upper_bound(x);
    if (it == mp.begin()) continue;
    --it;

    auto [key, cnt] = *it;
    if (key == 0) continue;
    mp.erase(it);
    mp[key - 1] += cnt;
  }

  vector<int> arr;
  for (auto [k, v] : mp) {
    while (v--) arr.push_back(k);
  }

  for (int i = 0; i < n; i++) {
    int id = ids[i];
    int cur = arr[i];
    int dt = dist[id] - cur;
    auto [y, x] = yx[id];
    int cut = min<int>(abs(y), dt);
    if (y < 0) {
      y += cut;
    } else {
      y -= cut;
    }

    cut = dt - cut;
    if (x < 0) {
      x += cut;
    } else {
      x -= cut;
    }
    yx[id] = {y, x};
  }

  for (auto [y, x] : yx) cout << x << " " << y << "\n";

  return 0;
}