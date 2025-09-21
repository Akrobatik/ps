// Title : 2vs2 배스킨라빈스 31
// Link  : https://www.acmicpc.net/problem/34402 
// Time  : 80 ms
// Memory: 2024 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<pair<int, int>> ans;

  int t;
  cin >> t;
  while (t--) {
    int64_t n, k;
    cin >> n >> k;
    --n;

    int64_t x1 = k + 1, y1 = n % x1;
    int64_t x2 = x1 << 1, y2 = n % x2;

    ans.clear();
    if (y1) {
      ans.push_back({1, 3});
    } else {
      ans.push_back({2, 4});
    }
    if (1 <= y2 && y2 <= x1) {
      ans.push_back({1, 4});
    } else {
      ans.push_back({2, 3});
    }
    if (2 <= y2) {
      ans.push_back({1, 2});
    } else {
      ans.push_back({3, 4});
    }
    sort(ans.begin(), ans.end());

    for (auto [a, b] : ans) cout << "(" << a << "," << b << ") ";
    cout << "\n";
  }

  return 0;
}
