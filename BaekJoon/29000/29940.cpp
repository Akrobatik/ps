// Title : Sum
// Link  : https://www.acmicpc.net/problem/29940 
// Time  : 8 ms
// Memory: 2412 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, s;
  cin >> n >> s;
  vector<int> arr(n);
  for (auto& e : arr) cin >> e;

  int l = 0, r = n - 1, cnt = 0;
  while (l < r) {
    int x = arr[l] + arr[r];
    if (x == s) ++cnt;

    if (x <= s) {
      ++l;
    } else {
      --r;
    }
  }
  cout << cnt;

  return 0;
}
