// Title : 게리맨더링
// Link  : https://www.acmicpc.net/problem/28433 
// Time  : 28 ms
// Memory: 3192 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<int> arr;

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    arr.resize(n);
    for (auto& e : arr) cin >> e;

    int idx = 0, cnt = 0;
    while (idx < n) {
      int64_t sum = arr[idx++];
      if (sum == 0) continue;

      if (sum < 0) {
        while (idx < n && arr[idx] <= 0) sum += arr[idx++];
        sum += (idx < n ? arr[idx] : 0);
        if (sum <= 0) {
          --cnt;
          continue;
        }
        ++idx;
      }

      while (idx < n && arr[idx] <= 0 && (sum += arr[idx]) > 0) ++idx;
      ++cnt;
    }
    cout << (cnt > 0 ? "YES\n" : "NO\n");
  }

  return 0;
}
