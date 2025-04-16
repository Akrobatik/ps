// Title : 트랙 정리하기
// Link  : https://www.acmicpc.net/problem/32689 
// Time  : 20 ms
// Memory: 2804 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> arr(n);
  for (auto& e : arr) cin >> e;

  bool none = true;
  for (auto e : arr) {
    if (e == 0) continue;
    none = false;
    break;
  }

  if (none) {
    cout << "0";
    return 0;
  }

  bool mr = true;
  int l = 0, r = n - 1, x = 0;
  int64_t ans = l;
  for (;;) {
    while (l < r && arr[l] == 0) ++l;
    while (l < r && arr[r] == 0) --r;

    if (l == r) {
      if (arr[l] == 0) break;
      if (mr) {
        if (l >= x)
          ans += l - x;
        else
          ans += l + n - x;
        --arr[l];
      } else {
        ans += n + x - r;
        --arr[r];
      }
      ans += (int64_t)n * arr[l];
      break;
    } else {
      int minn = min<int>(arr[l], arr[r]);
      if (minn > 1) {
        ans += (int64_t)(n + l - r) * (minn - 1) * 2;
        arr[l] -= minn - 1;
        arr[r] -= minn - 1;
      }
    }

    if (mr) {
      if (l >= x)
        ans += l - x;
      else
        ans += l + n - x;
      x = l;
      --arr[l];
      mr = false;
    } else {
      ans += n + x - r;
      x = r;
      --arr[r];
      mr = true;
    }
  }
  cout << ans;

  return 0;
}
