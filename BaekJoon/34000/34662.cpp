// Title : 월향 수목원
// Link  : https://www.acmicpc.net/problem/34662 
// Time  : 1836 ms
// Memory: 254824 KB

#include <bits/stdc++.h>

using namespace std;

constexpr int kMax = 2e5;

vector<int> group[kMax + 1];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<int64_t> rem(n + 1), add(n + 1), cut(n + 1, 1), time(n + 1), out(n + 1);
  vector<pair<int, int>> lr(n + 1), link(n + 2);
  link[0] = {0, 1}, link[n + 1] = {n, n + 1};

  auto Merge = [&](int x) {
    auto [l, r] = link[x];
    link[l].second = r;
    link[r].first = l;
  };

  for (int i = 1; i <= n; i++) {
    int a, x, v;
    cin >> a >> x >> v;

    int l = max<int>(i - x, 1), r = min<int>(i + x, n);
    rem[i] = out[i] = a;
    add[i] = v;
    lr[i] = {l, r};
    link[i] = {i - 1, i + 1};

    group[a].push_back(i);
  }

  vector<int> memo(n + 2);
  iota(memo.begin(), memo.end(), 0);

  auto Find = [&](int id) {
    while (id != memo[id]) {
      int par = memo[id];
      id = memo[id] = memo[par];
    }
    return id;
  };

  auto Union = [&](int a, int b) {
    a = Find(a), b = Find(b);
    if (a < b) swap(a, b);
    memo[b] = a;
  };

  int ans = 0, cnt = 0;
  vector<int64_t> arr(n + 2);
  vector<int> used(n + 2), tmp;
  for (int t = 1; cnt < n && t <= kMax; t++) {
    auto& g = group[t];
    for (auto& i : views::reverse(g)) {
      if (out[i] < t) swap(i, g.back()), g.pop_back();
    }

    if (!g.empty()) {
      ans = t;
      cnt += g.size();

      tmp.clear();
      for (auto i : g) {
        Merge(i);
        Union(i, i + 1);
        auto [l, r] = lr[i];
        arr[l] += add[i], arr[r + 1] -= add[i];
        if (!used[l]) used[l] = 1, tmp.push_back(l);
        if (!used[r + 1]) used[r + 1] = 1, tmp.push_back(r + 1);
      }
      sort(tmp.begin(), tmp.end());

      int64_t acc = 0, p = 0;
      for (auto i : tmp) {
        if (acc == 0) {
          p = Find(i);
        } else {
          while (p < i) {
            int dt = t - time[p];
            rem[p] -= cut[p] * dt;
            cut[p] += acc;
            time[p] = t;

            int extra = (rem[p] + cut[p] - 1) / cut[p];
            int old = out[p], cur = t + extra;
            if (cur < old) {
              out[p] = cur;
              group[cur].push_back(p);
            }

            p = link[p].second;
          }
        }
        acc += arr[i];
        arr[i] = 0, used[i] = 0;
      }
    }

    g.clear();
    g.shrink_to_fit();
  }
  cout << ans;

  return 0;
}