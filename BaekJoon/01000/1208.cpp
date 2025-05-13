// Title : 부분수열의 합 2
// Link  : https://www.acmicpc.net/problem/1208 
// Time  : 500 ms
// Memory: 58784 KB

#include <bits/stdc++.h>

using namespace std;

map<int, int> Count(span<const int> arr) {
  map<int, int> memo;
  memo[0] = 1;
  for (auto e : arr) {
    map<int, int> mnxt;
    for (auto [x, cnt] : memo) {
      mnxt[x] += cnt;
      mnxt[x + e] += cnt;
    }
    memo.swap(mnxt);
  }
  return memo;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, s;
  cin >> n >> s;

  vector<int> arr(n);
  for (auto& e : arr) cin >> e;

  int half = n >> 1;
  span<int> lrr(arr.begin(), arr.begin() + half);
  span<int> rrr(arr.begin() + half, arr.end());

  auto lm = Count(lrr), rm = Count(rrr);

  int64_t cnt = 0;
  for (auto [x, c] : lm) {
    if (auto it = rm.find(s - x); it != rm.end()) cnt += (int64_t)c * it->second;
  }
  cout << cnt - (s == 0);

  return 0;
}
