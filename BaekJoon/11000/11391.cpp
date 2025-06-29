// Title : 분배
// Link  : https://www.acmicpc.net/problem/11391 
// Time  : 8 ms
// Memory: 2280 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;

  int limit = 1 << n, mask = limit - 1;
  vector<pair<int, int>> cands;
  cands.reserve(limit >> 1);
  for (int i = 0; i < limit; i++) {
    int l = i, r = i ^ mask;
    if (l > r) continue;
    cands.push_back({l, r});
  }

  int ng = 1 << k, ne = (limit / ng) >> 1;
  for (int i = 0; i < ng; i++) {
    for (int j = 0; j < ne; j++) {
      auto [l, r] = cands.back();
      cands.pop_back();
      cout << l << " " << r << " ";
    }
    cout << "\n";
  }

  return 0;
}