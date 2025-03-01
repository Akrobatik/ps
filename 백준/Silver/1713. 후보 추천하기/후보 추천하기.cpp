#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  map<int, int> mp;
  for (int i = 0; i < m; i++) {
    int v;
    cin >> v;
    if (auto it = mp.find(v); it != mp.end()) {
      ++it->second;
    } else {
      if (mp.size() == n) {
        int minn = INT_MAX, mini, minp;
        for (auto [id, info] : mp) {
          int cnt = info & 0xFFFF;
          int pos = info >> 16;
          if (minn > cnt) {
            minn = cnt;
            mini = id;
            minp = pos;
          } else if (minn == cnt) {
            if (minp > pos) mini = id, minp = pos;
          }
        }
        mp.erase(mini);
      }
      mp[v] = (i << 16) | 1;
    }
  }

  for (auto [id, _] : mp) cout << id << " ";

  return 0;
}
