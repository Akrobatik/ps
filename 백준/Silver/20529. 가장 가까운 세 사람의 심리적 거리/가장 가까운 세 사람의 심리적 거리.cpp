#include <bits/stdc++.h>

using namespace std;

uint32_t memo[100000];

int Calc(int a, int b) {
  uint32_t x = memo[a] ^ memo[b];
  int res = 0;
  for (int i = 0; i < 4; i++) {
    res += (x & 0xFF) != 0;
    x >>= 8;
  }
  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    char s[8];
    for (int i = 0; i < n; i++) {
      cin >> s;
      memo[i] = *(uint32_t*)s;
    }

    if (n > 32) {
      cout << "0\n";
      continue;
    }

    int minn = INT_MAX;
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        for (int k = j + 1; k < n; k++) {
          int x = Calc(i, j) + Calc(j, k) + Calc(k, i);
          if (minn > x) minn = x;
        }
      }
    }
    cout << minn << "\n";
  }

  return 0;
}
