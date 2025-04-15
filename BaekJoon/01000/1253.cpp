// Title : 좋다
// Link  : https://www.acmicpc.net/problem/1253 
// Time  : 16 ms
// Memory: 2156 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int64_t> arr(n);
  for (auto& e : arr) cin >> e;
  sort(arr.begin(), arr.end());

  auto Check = [&](int i) {
    int64_t x = arr[i];
    int l = 0, r = arr.size() - 1;
    while (l < r) {
      if (l == i) {
        ++l;
        continue;
      }
      if (r == i) {
        --r;
        continue;
      }

      if (arr[l] + arr[r] == x) return true;
      if (arr[l] + arr[r] < x) {
        ++l;
      } else {
        --r;
      }
    }
    return false;
  };

  int cnt = 0;
  for (int i = 0; i < n; i++) {
    cnt += Check(i);
  }
  cout << cnt;

  return 0;
}
