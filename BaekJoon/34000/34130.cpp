// Title : Yet Another Stone Game
// Link  : https://www.acmicpc.net/problem/34130 
// Time  : 44 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;

    int cnt = 0, minn = INT_MAX;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      cnt += (x & 1);
      minn = min<int>(minn, x);
    }

    if (n == k) {
      cout << (cnt > 0 ? "First\n" : "Second\n");
      continue;
    }

    if (n == k + 1) {
      cout << (1 <= cnt && cnt <= k ? "First\n" : "Second\n");
      continue;
    }

    if (k == 1) {
      cout << (cnt % 2 == 1 ? "First\n" : "Second\n");
      continue;
    }

    cout << (cnt > 0 && (n != cnt + 1 || minn % 2 == 1) ? "First\n" : "Second\n");
  }

  return 0;
}
