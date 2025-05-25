// Title : $K$-POP
// Link  : https://www.acmicpc.net/problem/33977 
// Time  : 12 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  int minn = INT_MAX, bl, br;
  for (int i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      int l = i, r = n / i;
      if (minn > l + r) minn = l + r, bl = l, br = r;
    }
  }

  cout << minn << "\n";
  if (bl == 1) {
    for (int i = 1; i <= br; i++) {
      cout << i << " " << i + 1 << "\n";
    }
  } else {
    for (int i = 1; i < br; i++) {
      cout << i << " " << i + 1 << "\n";
    }
    cout << br << " " << bl + br << "\n";
    for (int i = 1; i < bl; i++) {
      cout << i << " " << br + i << "\n";
    }
  }

  return 0;
}
