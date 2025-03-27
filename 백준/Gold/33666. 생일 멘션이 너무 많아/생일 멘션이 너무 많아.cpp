#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  int64_t cnt = 0, sum = 0;
  vector<int> arr(n);
  for (auto& e : arr) {
    cin >> e;
    if (e != 1) ++cnt, sum += e;
  }

  int64_t avg = cnt ? sum / cnt : 0;
  for (auto& e : arr) {
    if (e > avg) e = 1;
    if (e <= m) continue;
    cout << "-1";
    return 0;
  }
  sort(arr.begin(), arr.end());

  vector<int> ans(m);
  int l = 0;
  for (int i = 0; i < n; i++) {
    int r = arr[i];
    while (l < r) ans[l++] = n - i;
  }

  for (auto e : ans) cout << e << " ";

  return 0;
}
