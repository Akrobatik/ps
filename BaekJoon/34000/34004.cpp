// Title : 메이플스토리2 장례식
// Link  : https://www.acmicpc.net/problem/34004 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<int> arr, brr;
  for (int i = 1; i <= 100; i++) {
    arr.push_back(i * i * i);
    brr.push_back(i * i);
  }

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int x = arr.rend() - lower_bound(arr.rbegin(), arr.rend(), n, greater<int>());
    int r = n - x * x * x;
    int r1 = x * x, r2 = r1 + x;

    int cnt = x * x * 6;
    if (r == 0) {
      cout << cnt << "\n";
      continue;
    }

    if (r <= r1) {
      int y = brr.rend() - lower_bound(brr.rbegin(), brr.rend(), r, greater<int>());
      int z = y + (r != y * y);
      y += (r > y * (y + 1));
      cout << cnt + (y + z) * 2 << "\n";
      continue;
    }

    r -= r1;
    cnt += x * 4;
    if (r <= r2) {
      int y = brr.rend() - lower_bound(brr.rbegin(), brr.rend(), r, greater<int>());
      int z = y + (r != y * y);
      y += (r > y * (y + 1));
      cout << cnt + (y + z) * 2 << "\n";
      continue;
    }

    r -= r2;
    cnt += x * 4 + 2;
    int y = brr.rend() - lower_bound(brr.rbegin(), brr.rend(), r, greater<int>());
    int z = y + (r != y * y);
    y += (r > y * (y + 1));
    cout << cnt + (y + z) * 2 << "\n";
  }

  return 0;
}
