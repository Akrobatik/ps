#include <bits/stdc++.h>

using namespace std;

int cnt;
vector<int> a, b;
map<int, set<int>> ma, mb;
map<int64_t, set<int>> mab;
vector<pair<int, int>> swaps;

bool Single() {
  for (auto& [x, is] : ma) {
    if (!mb.contains(x)) continue;
    int i = *is.begin();
    int j = *mb[x].begin();
    ma[a[i]].erase(i);
    ma[a[j]].erase(j);
    mb[b[i]].erase(i);
    swap(a[i], a[j]);
    swaps.push_back({i, j});
    ma[a[j]].insert(j);
    return true;
  }
  return false;
}

bool Triple() {
  for (auto& [x, is] : ma) {
    if (!mb.contains(x)) continue;
    for (int i : is) {
      for (int j : mb[x]) {
        if (!mb.contains(a[j])) continue;
        for (int k : mb[a[j]]) {
          if (a[k] == b[i]) {
            swap(a[i], a[j]);
            swap(a[j], a[k]);
            swaps.push_back({i, j});
            swaps.push_back({j, k});
            return true;
          }
        }
      }
    }
  }
  return false;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;

  a.resize(n), b.resize(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) cin >> b[i];

  for (int i = 0; i < n; i++) {
    if (a[i] == b[i]) {
      ++cnt;
    } else {
      int64_t ab = ((int64_t)a[i] << 32) | b[i];
      int64_t ba = ((int64_t)b[i] << 32) | a[i];
      if (k && mab.contains(ba) && !mab[ba].empty()) {
        int j = *mab[ba].begin();
        --k;
        cnt += 2;
        ma[a[j]].erase(j);
        mb[b[j]].erase(j);
        mab[ba].erase(j);
        swap(a[i], a[j]);
        swaps.push_back({i, j});
      } else {
        ma[a[i]].insert(i);
        mb[b[i]].insert(i);
        mab[ab].insert(i);
      }
    }
  }

  if (k == 2 && Triple()) {
    k = 0;
    cnt += 3;
  }

  while (k-- && Single()) ++cnt;

  cout << cnt << "\n";
  for (auto e : a) cout << e << " ";
  cout << "\n";
  for (auto e : b) cout << e << " ";
  cout << "\n";
  cout << swaps.size() << "\n";
  for (auto [i, j] : swaps) cout << "A " << i + 1 << " " << j + 1 << "\n";

  return 0;
}
