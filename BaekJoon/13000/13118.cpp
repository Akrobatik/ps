// Title : 뉴턴과 사과
// Link  : https://www.acmicpc.net/problem/13118
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<int64_t> arr(4);
  for (auto& e : arr) cin >> e;
  int64_t x, y, r;
  cin >> x >> y >> r;

  int ans = 0;
  for (int i = 0; i < 4; i++) {
    if (x == arr[i]) {
      ans = i + 1;
      break;
    }
  }
  cout << ans;

  return 0;
}
