// Title : KHU와 DKU
// Link  : https://www.acmicpc.net/problem/34859 
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
    int n, d, h, k, u;
    cin >> n >> d >> h >> k >> u;

    cout << "YES\n";
    if (h <= n && d <= n) {
      while (d--) cout << 'D';
      while (k--) cout << 'K';
      while (u--) cout << 'U';
      while (h--) cout << 'H';
    } else {
      while (k--) cout << 'K';
      while (d--) cout << 'D';
      while (h--) cout << 'H';
      while (u--) cout << 'U';
    }
    cout << "\n";
  }

  return 0;
}