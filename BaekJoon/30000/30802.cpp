// Title : 웰컴 키트
// Link  : https://www.acmicpc.net/problem/30802
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  int nums[6];
  for (int i = 0; i < 6; i++) cin >> nums[i];
  int t, p;
  cin >> t >> p;

  int ans_t = 0;
  for (int i = 0; i < 6; i++) {
    auto dv = div(nums[i], t);
    ans_t += dv.quot + (dv.rem != 0);
  }
  auto ans_p = div(n, p);

  cout << ans_t << "\n"
       << ans_p.quot << " " << ans_p.rem;

  return 0;
}
