// Title : List of Unique Numbers
// Link  : https://www.acmicpc.net/problem/13144 
// Time  : 8 ms
// Memory: 2412 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> arr(n);
  for (auto& e : arr) cin >> e;

  bool memo[100001] = {};

  int64_t sum = 0;
  int l = 0, r = 0;
  while (r < n) {
    while (r < n && !memo[arr[r]]) memo[arr[r++]] = true;
    int64_t cnt = r - l;
    sum += cnt * (cnt + 1) / 2;
    if (r != n) sum -= cnt * (cnt - 1) / 2;
    memo[arr[l++]] = false;
  }
  cout << sum;

  return 0;
}
