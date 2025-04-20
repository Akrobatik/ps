// Title : K-Regular Array
// Link  : https://www.acmicpc.net/problem/33793 
// Time  : 20 ms
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
    int x = (n + k - 1) / k * k;
    for (int i = 0; i < n; i++) {
      cout << (--x % k) + 1 << " ";
    }
    cout << "\n";
  }

  return 0;
}
