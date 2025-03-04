#include <bits/stdc++.h>

using namespace std;

int n, k, cnt;
vector<int> a, b;
unordered_map<int, unordered_set<int>> ma, mb;
unordered_map<int64_t, unordered_set<int>> mab;
vector<pair<int, int>> swaps;

void Swap(int i, int j) {
  int res = 0;
  res -= (a[i] == b[i]) + (a[j] == b[j]);

  ma[a[i]].erase(i), ma[a[j]].erase(j);
  mb[b[i]].erase(i), mb[b[j]].erase(j);
  mab[((int64_t)a[i] << 32) | b[i]].erase(i);
  mab[((int64_t)a[j] << 32) | b[j]].erase(j);
  swap(a[i], a[j]);
  --k;
  swaps.push_back({i, j});

  for (auto e : {i, j}) {
    if (a[e] == b[e]) continue;
    ma[a[e]].insert(e);
    mb[b[e]].insert(e);
    mab[((int64_t)a[e] << 32) | b[e]].insert(e);
  }

  res += (a[i] == b[i]) + (a[j] == b[j]);
  cnt += res;
}

bool Single() {
  for (auto& [x, is] : ma) {
    if (is.empty() || mb[x].empty()) continue;
    Swap(*is.begin(), *mb[x].begin());
    return true;
  }
  return false;
}

bool Triple() {
  set<int64_t> visited;
  for (auto& [x, is] : ma) {
    if (is.empty()) continue;
    int64_t ab = ((int64_t)x << 32);
    for (int j : mb[x]) {
      if (visited.contains(ab | a[j])) continue;
      visited.insert(ab | a[j]);
      for (int k : mb[a[j]]) {
        if (mab[((int64_t)x << 32) | a[k]].empty()) continue;
        int i = *mab[((int64_t)x << 32) | a[k]].begin();
        Swap(i, k);
        Swap(j, k);
        return true;
      }
    }
  }
  return false;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> k;
  a.resize(n), b.resize(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) cin >> b[i];

  for (int i = 0; i < n; i++) {
    cnt += (a[i] == b[i]);
    if (k && a[i] != b[i]) {
      int64_t ab = ((int64_t)a[i] << 32) | b[i];
      int64_t ba = ((int64_t)b[i] << 32) | a[i];
      ma[a[i]].insert(i);
      mb[b[i]].insert(i);
      mab[ab].insert(i);
      if (!mab[ba].empty()) {
        Swap(i, *mab[ba].begin());
      }
    }
  }

  if (k == 2) Triple();
  while (k && Single());

  cout << cnt << "\n";
  for (auto e : a) cout << e << " ";
  cout << "\n";
  for (auto e : b) cout << e << " ";
  cout << "\n";
  cout << swaps.size() << "\n";
  for (auto [i, j] : swaps) cout << "A " << i + 1 << " " << j + 1 << "\n";

  return 0;
}
