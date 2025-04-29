// Title : 좋은 구간
// Link  : https://www.acmicpc.net/problem/1059 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> arr(n);
  for (auto& e : arr) cin >> e;
  sort(arr.begin(), arr.end());

  int x;
  cin >> x;
  auto it = lower_bound(arr.begin(), arr.end(), x);
  if (*it == x) {
    cout << "0";
  } else if (it != arr.begin()) {
    int r = *it, l = *--it;
    cout << (r - x) * (x - l) - 1;
  } else {
    int r = *it, l = 0;
    cout << (r - x) * (x - l) - 1;
  }

  return 0;
}
