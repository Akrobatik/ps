// Title : 스터디 그룹
// Link  : https://www.acmicpc.net/problem/14572 
// Time  : 228 ms
// Memory: 17692 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n, k, d;
  cin >> n >> k >> d;
  vector<pair<int, vector<int>>> arr(n);
  for (auto& [lv, algo] : arr) {
    int m;
    cin >> m >> lv;
    algo.resize(m);
    for (auto& e : algo) cin >> e;
  }
  sort(arr.begin(), arr.end());

  int sum = 0, cnt = 0;
  int memo[31] = {};

  auto Push = [&](int id) {
    ++cnt;
    for (auto e : arr[id].second) {
      if (memo[e]++ == 0) ++sum;
    }
  };

  auto Pop = [&](int id) {
    --cnt;
    for (auto e : arr[id].second) {
      if (--memo[e] == 0) --sum;
    }
  };

  auto All = [&]() {
    int all = 0;
    for (int i = 1; i <= k; i++) all += (memo[i] == cnt);
    return all;
  };

  int64_t maxx = 0;
  int l = 0, r = 0;
  while (r != n) {
    int lv = arr[l].first;
    while (r < n && arr[r].first - lv <= d) Push(r++);
    maxx = max<int64_t>(maxx, (int64_t)(sum - All()) * cnt);
    while (l < r && arr[l].first == lv) Pop(l++);
  }
  cout << maxx;

  return 0;
}
