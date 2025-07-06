// Title : 아귀도
// Link  : https://www.acmicpc.net/problem/34046 
// Time  : 216 ms
// Memory: 48940 KB

#include <bits/stdc++.h>

using namespace std;

constexpr int kMod = 1e9 + 7;

vector<int> edges[200001];
int in[200001], out[200001], order[200001];
int idx;

void Traverse(int cur, int par) {
  in[cur] = ++idx;
  order[idx] = cur;
  for (auto nxt : edges[cur]) {
    if (nxt == par) continue;
    Traverse(nxt, cur);
  }
  out[cur] = idx;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> arr(n + 1);
  for (int i = 1; i <= n; i++) cin >> arr[i];

  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    edges[u].push_back(v);
    edges[v].push_back(u);
  }
  Traverse(1, 0);

  vector<vector<int>> st(n + 1), en(n + 1);
  for (int i = 1; i <= n; i++) {
    if (arr[i] == 0) continue;
    int x = arr[i];
    st[in[x]].push_back(i);
    en[out[x]].push_back(i);
  }

  map<int, int, greater<int>> mp;
  vector<int> memo(n + 1);
  for (int i = 1; i <= n; i++) {
    for (auto e : st[i]) ++mp[e];
    for (auto e : en[i - 1]) {
      auto it = mp.find(e);
      if (--(it->second) == 0) mp.erase(it);
    }
    memo[order[i]] = mp.empty() ? 0 : mp.begin()->first;
  }

  vector<int> zero;
  vector<bool> used(n + 1);
  for (int i = 1; i <= n; i++) {
    if (arr[i] == 0) {
      zero.push_back(i);
    } else {
      used[arr[i]] = true;
    }
  }

  vector<int> cands;
  cands.reserve(zero.size());
  for (int i = 1; i <= n; i++) {
    if (used[i]) continue;
    auto it = upper_bound(zero.begin(), zero.end(), memo[i]);
    if (it == zero.end()) {
      cout << "0";
      return 0;
    }
    cands.push_back(it - zero.begin());
  }

  sort(cands.begin(), cands.end(), greater<int>());
  int64_t ans = 1, nc = cands.size();
  for (int i = 0; i < nc; i++) {
    int64_t rem = nc - cands[i] - i;
    if (rem <= 0) {
      cout << "0";
      return 0;
    }
    ans = ans * rem % kMod;
  }
  cout << ans;

  return 0;
}