// Title : 비슷한 단어
// Link  : https://www.acmicpc.net/problem/2179 
// Time  : 4 ms
// Memory: 2856 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<string> strs(n);
  for (auto& s : strs) cin >> s;

  vector<int> ids(n);
  iota(ids.begin(), ids.end(), 0);
  sort(ids.begin(), ids.end(), [&](int lhs, int rhs) {
    return strs[lhs] < strs[rhs];
  });

  vector<int> memo(n);
  for (int i = 1; i < n; i++) {
    int l = ids[i - 1], r = ids[i];
    int cnt = 0, ns = min<int>(strs[l].size(), strs[r].size());
    while (cnt < ns && strs[l][cnt] == strs[r][cnt]) ++cnt;
    memo[i] = cnt;
  }

  pair<int, int> ans;
  int idx = 1, minn = -1;
  while (idx < n) {
    int nxt = idx;
    while (nxt < n && memo[idx] == memo[nxt]) ++nxt;

    int l = INT_MAX, r = INT_MAX;
    for (int i = idx - 1; i < nxt; i++) {
      int id = ids[i];
      if (l > id) {
        r = l, l = id;
      } else if (r > id) {
        r = id;
      }
    }

    pair<int, int> lr = {l, r};
    if (minn < memo[idx] || (minn == memo[idx] && ans > lr)) {
      minn = memo[idx], ans = lr;
    }
    idx = nxt;
  }

  auto [l, r] = ans;
  cout << strs[l] << "\n"
       << strs[r];

  return 0;
}