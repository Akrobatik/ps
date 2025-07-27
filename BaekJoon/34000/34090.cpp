// Title : 중간 뒤집기
// Link  : https://www.acmicpc.net/problem/34090 
// Time  : 252 ms
// Memory: 23304 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  unordered_map<int, int> hm;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    ++hm[x];
  }

  int64_t ans = (int64_t)n * (n - 1) / 2 + 1;
  for (auto [x, cnt] : hm) {
    ans -= (int64_t)cnt * (cnt - 1) / 2;
  }
  cout << ans;

  return 0;
}
