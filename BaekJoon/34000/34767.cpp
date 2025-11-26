// Title : 뭐야 내 수열 돌려줘요
// Link  : https://www.acmicpc.net/problem/34767 
// Time  : 120 ms
// Memory: 17752 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<int64_t> arr(n << 1);
  for (auto& e : arr) cin >> e;

  map<int64_t, int64_t> mp;
  for (auto e : arr) ++mp[e];

  int64_t sum = accumulate(arr.begin(), arr.end(), 0LL) / (n + 1);
  auto it = mp.find(sum);
  if ((it->second -= 2) == 0) mp.erase(it);

  vector<int64_t> axr{0};
  while (!mp.empty()) {
    auto it = mp.begin();
    auto [iv, ic] = *it;
    mp.erase(it);

    int64_t val, cnt;
    if (iv * 2 == sum) {
      val = iv;
      cnt = ic >> 1;
    } else {
      auto jt = mp.find(sum - iv);
      auto [jv, jc] = *jt;
      mp.erase(jt);

      val = iv;
      cnt = ic;
    }

    while (cnt--) {
      axr.push_back(val);
    }
  }
  axr.push_back(sum);

  for (int i = 1; i <= n; i++) {
    cout << axr[i] - axr[i - 1] << " ";
  }

  return 0;
}