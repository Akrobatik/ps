// Title : 루미상관 수
// Link  : https://www.acmicpc.net/problem/35483 
// Time  : 4 ms
// Memory: 2920 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<int> arr;
  for (int i = 1; i < 10; i++) {
    arr.push_back(i);
  }
  for (int i = 1, x = 1; i < 10000; i++) {
    while (x * 10 <= i) x *= 10;
    int y = x * 10;

    arr.push_back(i * (y + 1));
    for (int j = 0; j < 10; j++) {
      arr.push_back((i * 10 + j) * y + i);
    }
  }
  sort(arr.begin(), arr.end());

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;

    int cnt = 0, l = 0, r = arr.size() - 1;
    while (l <= r) {
      int sum = arr[l] + arr[r];
      if (sum < n) {
        ++l;
      } else if (sum > n) {
        --r;
      } else {
        cnt += (l == r ? 1 : 2);
        ++l, --r;
      }
    }
    cout << cnt << "\n";
  }

  return 0;
}