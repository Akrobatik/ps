// Title : 두 수열 만들기
// Link  : https://www.acmicpc.net/problem/34189 
// Time  : 32 ms
// Memory: 2560 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  int m = n << 1;
  vector<int> cands(m);
  for (auto& e : cands) cin >> e;

  vector<int> ids(m);
  iota(ids.begin(), ids.end(), 0);

  auto Find = [&](int id) {
    while (id != ids[id]) {
      int par = ids[id];
      id = ids[id] = ids[par];
    }
    return id;
  };

  auto Union = [&](int a, int b) {
    a = Find(a), b = Find(b);
    if (a == b) return;
    if (a > b) swap(a, b);
    ids[b] = a;
  };

  for (int i = 0; i < m; i++) {
    int iv = cands[i];
    for (int j = i + 1; j < m; j++) {
      int jv = cands[j];
      if (has_single_bit((uint32_t)(iv ^ jv))) {
        Union(i, j);
      }
    }
  }

  vector<vector<int>> axr;
  for (int i = 0; i < m; i++) {
    if (ids[i] != i) continue;

    auto& vec = axr.emplace_back();
    for (int j = i; j < m; j++) {
      if (Find(j) == i) vec.push_back(j);
    }
  }

  int na = axr.size();
  vector<vector<bool>> memo(na + 1, vector<bool>(n + 1));
  memo[0][0] = true;
  for (int i = 0; i < na; i++) {
    int sz = axr[i].size();
    for (int j = 0; j <= n; j++) {
      memo[i + 1][j] = (memo[i][j] || (j >= sz && memo[i][j - sz]));
    }
  }

  if (!memo[na][n]) {
    cout << "-1";
    return 0;
  }

  vector<int> arr, brr;
  for (int i = na - 1, j = n; i >= 0; i--) {
    int sz = axr[i].size();
    if (sz <= j && memo[i][j - sz]) {
      j -= sz;
      for (auto e : axr[i]) arr.push_back(cands[e]);
    } else {
      for (auto e : axr[i]) brr.push_back(cands[e]);
    }
  }

  sort(arr.begin(), arr.end());
  sort(brr.begin(), brr.end());
  for (auto e : arr) cout << e << " ";
  cout << "\n";
  for (auto e : brr) cout << e << " ";

  return 0;
}
