// Title : Moo 게임
// Link  : https://www.acmicpc.net/problem/5904 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

using tup = tuple<int64_t, int64_t, int64_t>;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<tup> arr{{0, 3, 3}};
  for (int i = 0; i < 32; i++) {
    auto [l, r, m] = arr.back();
    int64_t x = i + 4;
    arr.push_back({m, m + x, (m << 1) + x});
  }

  int64_t len;
  cin >> len, --len;

  for (auto [l, r, m] : views::reverse(arr)) {
    if (len < l) continue;
    if (l <= len && len < r) {
      cout << "om"[l == len];
      break;
    }
    len -= r;
  }

  return 0;
}