// Title : 합이 $K$ 이하
// Link  : https://www.acmicpc.net/problem/33071 
// Time  : 144 ms
// Memory: 15324 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;

  vector<pair<int, int>> arr(n);
  for (auto& [a, b] : arr) cin >> a >> b;
  sort(arr.begin(), arr.end());

  map<int64_t, int, greater<int64_t>> mp;

  vector<vector<int>> axr;
  int idx = 0;
  while (idx < n) {
    int nxt = idx;
    while (nxt < n && arr[idx].first == arr[nxt].first) ++nxt;
    auto& vec = axr.emplace_back();
    vec.reserve(nxt - idx);
    while (idx < nxt) {
      int x = arr[idx++].second;
      ++mp[x];
      vec.push_back(x);
    }
  }

  sort(axr.begin(), axr.end(), [&](const vector<int>& lhs, const vector<int>& rhs) {
    return lhs.size() < rhs.size();
  });

  int maxx = INT_MIN;
  for (int i = 0; i + 1 < axr.size(); i++) {
    auto& vec = axr[i];
    for (auto e : vec) {
      auto it = mp.find(e);
      if (--(it->second) == 0) mp.erase(it);
    }

    int cur = INT_MIN;
    auto it = mp.lower_bound(vec[0]);
    for (int j = 0; j < vec.size(); j++) {
      int64_t x = (int64_t)k - vec[j];
      auto it = mp.lower_bound(x);
      if (it != mp.end()) maxx = max<int>(maxx, vec[j] + it->first);
    }

    for (auto e : vec) {
      ++mp[e];
    }
  }

  if (maxx != INT_MIN) {
    cout << maxx;
  } else {
    cout << "NO";
  }

  return 0;
}
