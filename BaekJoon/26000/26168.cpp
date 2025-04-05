// Title : 배열 전체 탐색하기
// Link  : https://www.acmicpc.net/problem/26168
// Time  : 80 ms
// Memory: 2808 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  vector<int64_t> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a.begin(), a.end());
  while (m--) {
    int q;
    cin >> q;
    if (q == 1) {
      int64_t v;
      cin >> v;
      cout << a.end() - lower_bound(a.begin(), a.end(), v) << "\n";
    } else if (q == 2) {
      int64_t v;
      cin >> v;
      cout << a.end() - upper_bound(a.begin(), a.end(), v) << "\n";
    } else {
      int64_t v1, v2;
      cin >> v1 >> v2;
      auto b = lower_bound(a.begin(), a.end(), v1);
      auto e = upper_bound(a.begin(), a.end(), v2);
      cout << e - b << "\n";
    }
  }

  return 0;
}
