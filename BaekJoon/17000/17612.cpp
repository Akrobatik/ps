// Title : 쇼핑몰
// Link  : https://www.acmicpc.net/problem/17612 
// Time  : 32 ms
// Memory: 4220 KB

#include <bits/stdc++.h>

using namespace std;

using tup = tuple<int, int, int>;

constexpr int kMax = 1 << 17;

int tree[kMax << 1];

pair<int, int> Query() {
  int node = 1;
  int minn = tree[1];
  while (node < kMax) {
    if (tree[node << 1] == minn) {
      node <<= 1;
    } else {
      node = (node << 1) + 1;
    }
  }
  return {node - kMax, minn};
}

void Update(int idx, int value) {
  int node = idx + kMax;
  tree[node] = value;
  node >>= 1;
  while (node) tree[node] = min<int>(tree[node << 1], tree[(node << 1) + 1]), node >>= 1;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  fill_n(tree, kMax << 1, INT_MAX);

  int n, k;
  cin >> n >> k;
  vector<tup> out;
  out.reserve(n);

  for (int i = 0; i < k; i++) {
    int node = i + kMax;
    while (node && tree[node]) tree[node] = 0, node >>= 1;
  }

  while (n--) {
    int r, w;
    cin >> r >> w;
    auto [idx, minn] = Query();
    Update(idx, minn + w);
    out.push_back({minn + w, idx, r});
  }

  sort(out.begin(), out.end(), [](const tup& lhs, const tup& rhs) {
    auto [lt, lk, lr] = lhs;
    auto [rt, rk, rr] = rhs;
    return lt < rt || (lt == rt && lk > rk);
  });

  int64_t ans = 0;
  for (int64_t i = 0; i < out.size(); i++) {
    ans += (i + 1) * get<2>(out[i]);
  }
  cout << ans;

  return 0;
}
