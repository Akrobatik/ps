// Title : n, 3n, 5n
// Link  : https://www.acmicpc.net/problem/32162 
// Time  : 24 ms
// Memory: 2916 KB

#include <bits/stdc++.h>

using namespace std;

constexpr int kMax = 1e5;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<int> arr{0};
  for (int i = 1; arr.size() <= kMax; i++) {
    if (i % 3 == 0 || i % 5 == 0) {
      int x = i, y = 0;
      while (x % 3 == 0) x /= 3, ++y;
      while (x % 5 == 0) x /= 5, --y;
      if (y % 3) continue;
    }
    arr.push_back(i);
  }

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    cout << arr[n] << "\n";
  }

  return 0;
}
