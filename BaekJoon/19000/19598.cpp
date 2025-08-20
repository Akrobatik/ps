// Title : 최소 회의실 개수
// Link  : https://www.acmicpc.net/problem/19598 
// Time  : 36 ms
// Memory: 3588 KB

#include <bits/stdc++.h>

using namespace std;

constexpr int kMax = 1e5;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<pair<uint32_t, int>> arr;
  arr.reserve(n << 1);
  while (n--) {
    uint32_t s, e;
    cin >> s >> e;
    arr.push_back({s, 1});
    arr.push_back({e, -1});
  }
  sort(arr.begin(), arr.end());

  int cur = 0, maxx = 0;
  for (auto [x, y] : arr) {
    cur += y;
    maxx = max<int>(maxx, cur);
  }
  cout << maxx;

  return 0;
}