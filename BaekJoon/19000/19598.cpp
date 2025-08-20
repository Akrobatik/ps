// Title : 최소 회의실 개수
// Link  : https://www.acmicpc.net/problem/19598 
// Time  : 116 ms
// Memory: 11396 KB

#include <bits/stdc++.h>

using namespace std;

constexpr int kMax = 1e5;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  map<uint32_t, int> mp;
  while (n--) {
    uint32_t s, e;
    cin >> s >> e;
    ++mp[s], --mp[e];
  }

  int maxx = 0, cur = 0;
  for (auto& [k, v] : mp) {
    cur += v;
    maxx = max<int>(maxx, cur);
  }
  cout << maxx;

  return 0;
}