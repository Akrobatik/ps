// Title : 가장 긴 증가하는 부분 수열 6
// Link  : https://www.acmicpc.net/problem/17411 
// Time  : 460 ms
// Memory: 17652 KB

#include <bits/stdc++.h>

using namespace std;

constexpr int kMod = 1e9 + 7;

pair<int, int> tree[1000001];

pair<int, int> Calc(const pair<int, int>& a, const pair<int, int>& b) {
  if (a.first > b.first) return a;
  if (a.first < b.first) return b;
  int cnt = a.second + b.second;
  if (cnt >= kMod) cnt -= kMod;
  return {a.first, cnt};
}

void Update(int idx, int n, const pair<int, int>& x) {
  while (idx < n) tree[idx] = Calc(tree[idx], x), idx += (idx & -idx);
}

pair<int, int> Query(int idx) {
  pair<int, int> res{};
  while (idx) res = Calc(tree[idx], res), idx -= (idx & -idx);
  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> arr(n);
  for (auto& e : arr) cin >> e;
  auto brr = arr;
  sort(brr.begin(), brr.end());
  auto be = unique(brr.begin(), brr.end());
  for (auto& e : arr) e = lower_bound(brr.begin(), be, e) - brr.begin();

  int nmax = be - brr.begin() + 1;
  for (auto e : arr) {
    auto [len, cnt] = Query(e);
    Update(e + 1, nmax, {len + 1, cnt + (len == 0)});
  }
  auto [len, cnt] = Query(nmax - 1);
  cout << len << " " << cnt;

  return 0;
}
