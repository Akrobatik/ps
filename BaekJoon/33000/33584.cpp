// Title : 디미교도소
// Link  : https://www.acmicpc.net/problem/33584 
// Time  : 64 ms
// Memory: 5932 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> arr(n);
  for (auto& e : arr) cin >> e;

  int fwd = 0;
  for (int i = 0; i < n; i++) {
    if (arr[i] > i + 1) {
      if (fwd > arr[i]) {
        cout << "-1";
        return 0;
      }
      fwd = max<int>(fwd, arr[i]);
    }
  }
  int bwd = n;
  for (int i = n - 1; i >= 0; i--) {
    if (arr[i] < i + 1) {
      if (bwd < arr[i]) {
        cout << "-1";
        return 0;
      }
      bwd = min<int>(bwd, arr[i]);
    }
  }

  vector<int> tree(n + 1);

  auto Update = [&](int x) {
    for (; x <= n; x += x & (-x)) ++tree[x];
  };

  auto Query = [&](int x) {
    int res = 0;
    for (; x; x -= x & (-x)) res += tree[x];
    return res;
  };

  int64_t ans = 0;
  for (int i = 0; i < n; i++) {
    ans += i - Query(arr[i]);
    Update(arr[i]);
  }
  cout << ans;

  return 0;
}