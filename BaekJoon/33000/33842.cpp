// Title : 돌멩이 배치
// Link  : https://www.acmicpc.net/problem/33842 
// Time  : 24 ms
// Memory: 3188 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<int> arr;

  int t;
  cin >> t;
  while (t--) {
    int n, k, l, r, d;
    cin >> n >> k >> l >> r;
    arr.assign(n, 0);

    int s = ((int64_t)n * l + k - 1) / k;
    int x = 0;
    for (int i = 0; i < n; i++) {
      x += s;
      if (x >= n) x -= n, arr[i] = 1;
    }

    int sum = 0;
    for (int i = n - k; i < n; i++) {
      sum += arr[i];
    }

    bool ok = true;
    for (int i = 0; ok && i < n; i++) {
      sum += arr[i] - arr[(i + n - k) % n];
      ok = (l <= sum && sum <= r);
    }

    if (ok) {
      for (auto e : arr) cout << e << " ";
      cout << "\n";
    } else {
      cout << "-1\n";
    }
  }

  return 0;
}