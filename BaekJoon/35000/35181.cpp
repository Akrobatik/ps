// Title : Xoracle
// Link  : https://www.acmicpc.net/problem/35181 
// Time  : 4964 ms
// Memory: 14596 KB

#include <bits/stdc++.h>

using namespace std;

int Query(int a, int b) {
  cout << "? " << a << " " << b << endl;
  int res;
  cin >> res;
  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  vector<int> arr(n + 1);
  for (int i = 2; i <= n; i++) {
    arr[i] = Query(1, i);
  }

  int maxb = bit_width((uint32_t)(n - 1));
  vector<array<int, 2>> memo(maxb);
  for (int i = 0; i < maxb; i++) {
    int bit = 1 << i;
    for (int j = 0; j < 2; j++) {
      int val = bit * j;
      int64_t acc = val;
      for (int k = 2; k <= n; k++) {
        acc += (val ^ arr[k]) & bit;
      }
      memo[i][j] = acc;
    }
  }

  int64_t goal = (n - 1) << 1;
  for (int i = 1; i < min<int>(1 << maxb, n); i++) {
    int64_t cur = 0;
    for (int j = 0; j < maxb; j++) {
      cur += memo[j][(i >> j) & 1];
    }
    if (cur == goal) {
      bool ok = true;
      for (int j = 2; ok && j <= n; j++) {
        int x = (arr[j] ^ i);
        ok = (1 <= x && x < n);
      }
      if (!ok) continue;

      cout << "! " << i;
      for (int j = 2; j <= n; j++) {
        cout << " " << (arr[j] ^ i);
      }
      cout << endl;
      return 0;
    }
  }

  return 0;
}