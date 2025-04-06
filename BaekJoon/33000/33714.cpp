// Title : Min Max Mex
// Link  : https://www.acmicpc.net/problem/33714 
// Time  : 36 ms
// Memory: 2804 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int64_t n, k;
  cin >> n >> k;
  vector<int> arr(n);
  for (auto& e : arr) cin >> e;
  sort(arr.begin(), arr.end());

  int64_t minn = 0;
  auto it = arr.begin();
  while (it != arr.end() && *it == minn) {
    int64_t cnt = 0;
    while (it != arr.end() && *it == minn) ++cnt, ++it;
    if (cnt <= k) break;
    ++minn;
  }

  arr.erase(unique(arr.begin(), arr.end()), arr.end());

  int64_t maxx = k;
  it = arr.begin();
  while (it != arr.end() && *it++ <= maxx) ++maxx;

  cout << minn << "\n"
       << maxx;

  return 0;
}
