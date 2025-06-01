// Title : 내 생각에 A번인 단순 dfs 문제가 이 대회에서 E번이 되어버린 건에 관하여 (Easy)
// Link  : https://www.acmicpc.net/problem/18251 
// Time  : 132 ms
// Memory: 5228 KB

#include <bits/stdc++.h>

using namespace std;

vector<int> arr;
vector<vector<pair<int, int>>> idx;
int order;

void Traverse(int i, int depth, int maxd) {
  if (depth == maxd) return;
  Traverse(i << 1, depth + 1, maxd);
  idx[depth].push_back({order++, arr[i - 1]});
  Traverse((i << 1) + 1, depth + 1, maxd);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  arr.resize(n);
  int64_t maxx = INT64_MIN;
  for (auto& e : arr) cin >> e, maxx = max<int64_t>(maxx, e);

  if (maxx <= 0) {
    cout << maxx;
    return 0;
  }

  int maxd = countr_one((uint32_t)n);
  idx.resize(maxd);
  Traverse(1, 0, maxd);

  fill(arr.begin(), arr.end(), 0);

  for (int k = 0; k < maxd; k++) {
    for (int i = maxd - 1; i >= k; i--) {
      for (auto [p, v] : idx[i]) arr[p] = v;

      int64_t cur = 0;
      for (int j = 0; j < n; j++) {
        cur = max<int64_t>(cur, 0) + arr[j];
        maxx = max<int64_t>(maxx, cur);
      }
    }

    for (int i = maxd - 1; i > k; i--) {
      for (auto [p, v] : idx[i]) arr[p] = 0;

      int64_t cur = 0;
      for (int j = 0; j < n; j++) {
        cur = max<int64_t>(cur, 0) + arr[j];
        maxx = max<int64_t>(maxx, cur);
      }
    }

    for (auto [p, v] : idx[k]) arr[p] = 0;
  }
  cout << maxx;

  return 0;
}
