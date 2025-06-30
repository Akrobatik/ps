// Title : 우선순위 큐와 시뮬레이션
// Link  : https://www.acmicpc.net/problem/32718 
// Time  : 108 ms
// Memory: 2808 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k, t;
  cin >> n >> k >> t;

  vector<int> arr(n);
  for (auto& e : arr) cin >> e, e %= k;
  sort(arr.begin(), arr.end());
  arr.erase(unique(arr.begin(), arr.end()), arr.end());
  n = arr.size();

  int mid = 0;
  while (t--) {
    int x;
    cin >> x;
    mid = (mid + x) % k;

    if (auto it = upper_bound(arr.begin(), arr.end(), k - mid - 1); it != arr.begin()) {
      cout << *--it + mid << " ";
    } else {
      cout << arr.back() + mid - k << "\n";
    }
  }

  return 0;
}
