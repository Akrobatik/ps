// Title : 외계 선인장
// Link  : https://www.acmicpc.net/problem/25302 
// Time  : 2000 ms
// Memory: 279364 KB

#include "cactus.h"
//

#include <bits/stdc++.h>

using namespace std;

constexpr int64_t kInf = 1e18;

int nmax;
vector<vector<pair<int, int64_t>>> tree;
vector<pair<int, int64_t>> tmp;

void Update(int l, int r, int64_t v) {
  tree[l + nmax].push_back({r, v});
}

void Pull(int i) {
  auto& mnode = tree[i];
  auto& lnode = tree[i << 1];
  auto& rnode = tree[i << 1 | 1];

  int64_t sz = lnode.size() + rnode.size();
  mnode.resize(sz);
  merge(lnode.begin(), lnode.end(), rnode.begin(), rnode.end(), mnode.begin());
}

void Prefix(int i) {
  auto& mnode = tree[i];

  tmp.clear();
  int64_t acc = 0, idx = 0, sz = mnode.size();
  while (idx < sz) {
    int64_t val = mnode[idx].first, nxt = idx;
    while (nxt < sz && mnode[nxt].first == val) acc += mnode[nxt++].second;
    tmp.push_back({val, acc});
    idx = nxt;
  }
  swap(tmp, mnode);
}

void init(std::vector<int> H) {
  int n = H.size();
  nmax = bit_ceil((uint32_t)n);
  tree.assign(nmax << 1, vector<pair<int, int64_t>>());

  vector<int> hrr(n);
  vector<pair<int, int>> arr(n);
  for (int i = 0; i < n; i++) {
    int x = H[i];
    hrr[i] = x;
    arr[i] = {x, i};
  }
  sort(arr.begin(), arr.end(), greater<pair<int, int>>());

  int idx = 0;
  vector<int> stk;
  vector<pair<int, int>> upd;
  set<int> st;
  while (idx < n) {
    int val = arr[idx].first, nxt = idx;
    while (nxt < n && arr[nxt].first == val) {
      auto [h, i] = arr[nxt++];
      stk.push_back(i);
    }

    for (auto i : stk) {
      auto it = st.lower_bound(i);
      if (it != st.begin() && it != st.end()) {
        int rb = *it;
        int lb = *prev(it);
        upd.push_back({lb, rb});
      }
    }
    sort(upd.begin(), upd.end());
    upd.erase(unique(upd.begin(), upd.end()), upd.end());

    while (!upd.empty()) {
      auto [lb, rb] = upd.back();
      upd.pop_back();

      int ph = min<int>(hrr[lb], hrr[rb]);
      int64_t add = (int64_t)(rb - lb - 1) * (ph - val);
      Update(lb, rb, add);
    }

    while (!stk.empty()) {
      int i = stk.back();
      stk.pop_back();

      st.insert(i);
    }

    idx = nxt;
  }

  for (int i = 0; i < nmax; i++) {
    auto& node = tree[i + nmax];
    sort(node.begin(), node.end());
  }
  for (int i = nmax - 1; i > 0; i--) Pull(i);
  for (int i = 1; i < (nmax << 1); i++) Prefix(i);
}

long long query(int S, int E) {
  --S, --E;

  auto F = [&](int i) {
    auto& node = tree[i];
    auto it = upper_bound(node.begin(), node.end(), make_pair(E, kInf));
    return (it != node.begin() ? prev(it)->second : 0);
  };

  int64_t res = 0;
  for (int l = S + nmax, r = E + nmax + 1; l < r; l >>= 1, r >>= 1) {
    if (l & 1) res += F(l++);
    if (r & 1) res += F(--r);
  }
  return res;
}
