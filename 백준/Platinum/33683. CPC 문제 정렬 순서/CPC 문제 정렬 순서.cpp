#include <bits/stdc++.h>

using namespace std;

using tup = tuple<int, int, int>;

map<int, int> memo;

int Find(int x) {
  if (auto it = memo.find(x); it != memo.end()) {
    return it->second = Find(it->second);
  }
  return x;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  vector<tup> arr(n);
  for (int i = 0; i < n; i++) {
    int l, r;
    cin >> l >> r;
    arr[i] = {l, r, i};
  }
  sort(arr.begin(), arr.end(), [](const tup& lhs, const tup& rhs) {
    auto [ll, lr, li] = lhs;
    auto [rl, rr, ri] = rhs;
    return lr < rr || (lr == rr && ll < rl);
  });

  map<int, vector<int>> mp;
  for (auto [l, r, i] : arr) {
    int x = Find(l);
    if (x <= r) {
      memo[x] = x + 1;
    } else {
      x = l;
    }
    mp[x].push_back(i);
  }

  if (mp.size() < m) {
    cout << "-1";
    return 0;
  }

  vector<pair<int, int>> ans(n);
  int cnt = 0;
  for (auto& [x, vec] : mp) {
    if (cnt < m) ++cnt;
    for (auto i : vec) ans[i] = {x, cnt};
  }

  for (auto [x, g] : ans) cout << x << " " << g << "\n";

  return 0;
}
