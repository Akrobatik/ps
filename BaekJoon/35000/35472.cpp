// Title : 쉽고 간단한 문제
// Link  : https://www.acmicpc.net/problem/35472 
// Time  : 168 ms
// Memory: 7892 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<int> arr(n);
  for (auto& e : arr) cin >> e;

  vector<int> memo = arr;
  sort(memo.begin(), memo.end());
  memo.erase(unique(memo.begin(), memo.end()), memo.end());

  auto Idx = [&](int x) {
    return lower_bound(memo.begin(), memo.end(), x) - memo.begin();
  };

  int sz = memo.size();
  vector<int> val(sz);

  int nc = min<int>(sz, 3);
  vector<int> cands(nc);
  iota(cands.begin(), cands.end(), 0);

  for (auto e : arr) {
    e = Idx(e);
    int mv = 0, repl = 1;
    for (int i = 0; i < nc; i++) {
      int ci = cands[i];
      repl &= (e != ci);
      if (abs(memo[e] - memo[ci]) == 1) continue;
      if (mv <= val[ci]) mv = val[ci];
    }

    val[e] = mv + 1;
    if (repl) {
      for (int i = 1; i < nc; i++) {
        int& l = cands[i - 1];
        int& r = cands[i];
        if (val[l] < val[r]) swap(l, r);
      }
      cands[nc - 1] = e;
    }
  }

  int maxx = 0;
  for (auto e : cands) {
    maxx = max<int>(maxx, val[e]);
  }
  cout << maxx;

  return 0;
}