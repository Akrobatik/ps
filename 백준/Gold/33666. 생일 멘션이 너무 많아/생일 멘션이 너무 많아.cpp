#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  vector<int> arr(n);
  for (auto& e : arr) cin >> e;
  sort(arr.begin(), arr.end());

  int cnt = 0;
  int64_t sum = 0;
  for (auto e : arr) {
    if (e == 1) continue;
    ++cnt, sum += e;
  }

  auto avg = cnt ? sum / cnt : 0;
  for (auto& e : arr) {
    if (e > avg) e = 1;
    if (e <= m) continue;
    cout << "-1";
    return 0;
  }
  sort(arr.begin(), arr.end());

  for (int i = 1; i <= m; i++) {
    auto it = lower_bound(arr.begin(), arr.end(), i);
    cout << arr.end() - it << " ";
  }

  return 0;
}
