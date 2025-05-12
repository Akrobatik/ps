// Title : 태종대 낚시 맛집
// Link  : https://www.acmicpc.net/problem/33847 
// Time  : 76 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

using tup = tuple<int, int, int>;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, c;
  cin >> n >> c;
  vector<tup> arr(n);
  int maxx = 0;
  for (auto& [x, s, w] : arr) cin >> x >> s >> w, maxx += x;

  auto Calc = [&](int x) {
    int res = 0;
    bool used[100] = {};
    for (;;) {
      int idx = -1, mw = 0;
      for (int i = 0; i < n; i++) {
        if (used[i] || get<0>(arr[i]) > x) continue;
        if (mw < get<1>(arr[i])) mw = get<1>(arr[i]), idx = i;
      }
      if (idx == -1) break;
      used[idx] = true;
      res += get<2>(arr[idx]);
      x -= get<0>(arr[idx]);
    }
    return res;
  };

  int64_t ans = 0;
  for (int i = 1; i <= maxx; i++) {
    ans = max<int64_t>(ans, Calc(i) - (int64_t)c * i);
  }
  cout << ans;

  return 0;
}
