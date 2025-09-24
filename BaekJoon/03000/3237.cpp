// Title : UHODE
// Link  : https://www.acmicpc.net/problem/3237 
// Time  : 12 ms
// Memory: 2484 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  map<pair<int64_t, int64_t>, vector<int>> mp;
  vector<int> vis;
  for (int i = 1; i <= n; i++) {
    int64_t x, y;
    cin >> x >> y;
    mp[{x, y}].push_back(i);
  }

  int ns;
  string s;
  cin >> ns >> s;

  auto Check = [&](int64_t x, int64_t y) {
    for (int dx = -1; dx <= 1; dx++) {
      for (int dy = -1; dy <= 1; dy++) {
        int64_t xx = x + dx, yy = y + dy;
        auto it = mp.find({xx, yy});
        if (it != mp.end()) {
          vis.insert(vis.end(), it->second.begin(), it->second.end());
          mp.erase(it);
        }
      }
    }
  };

  int64_t x = 0, y = 0;
  Check(x, y);
  for (auto c : s) {
    if (c == 'I') {
      ++x;
    } else if (c == 'S') {
      ++y;
    } else if (c == 'Z') {
      --x;
    } else {
      --y;
    }
    Check(x, y);
  }

  sort(vis.begin(), vis.end());
  vis.erase(unique(vis.begin(), vis.end()), vis.end());

  if (vis.empty()) {
    cout << "-1";
  } else {
    for (auto e : vis) cout << e << "\n";
  }

  return 0;
}
