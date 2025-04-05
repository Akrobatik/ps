// Title : 5교시： 과학
// Link  : https://www.acmicpc.net/problem/33636
// Time  : 980 ms
// Memory: 101812 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<pair<int64_t, int64_t>> arr(n);
  for (auto& [c, w] : arr) cin >> w;
  for (auto& [c, w] : arr) cin >> c;
  sort(arr.begin(), arr.end());

  vector<pair<int64_t, vector<int64_t>>> brr;
  for (auto [c, w] : arr) {
    if (!brr.empty() && brr.back().first == c) {
      brr.back().second.push_back(w);
    } else {
      brr.push_back({c, vector<int64_t>(1, w)});
    }
  }

  n = brr.size();
  int na = n >> 1;

  unordered_map<int64_t, int64_t> ahm, bhm;
  vector<pair<int64_t, int64_t>> tmp;
  ahm[0] = 1, bhm[0] = 1;
  for (int i = 0; i < na; i++) {
    tmp.clear();
    int64_t c = brr[i].first;
    for (auto w : brr[i].second) {
      w *= (c - 5000);
      for (auto [ww, cnt] : ahm) {
        tmp.push_back({ww + w, cnt});
      }
    }
    for (auto [ww, cnt] : tmp) {
      ahm[ww] += cnt;
    }
  }
  for (int i = na; i < n; i++) {
    tmp.clear();
    int64_t c = brr[i].first;
    for (auto w : brr[i].second) {
      w *= (c - 5000);
      for (auto [ww, cnt] : bhm) {
        tmp.push_back({ww + w, cnt});
      }
    }
    for (auto [ww, cnt] : tmp) {
      bhm[ww] += cnt;
    }
  }

  int64_t ans = 0;
  for (auto [aw, ac] : ahm) {
    if (auto it = bhm.find(-aw); it != bhm.end()) {
      ans += ac * it->second;
    }
  }
  cout << ans - 1;

  return 0;
}
