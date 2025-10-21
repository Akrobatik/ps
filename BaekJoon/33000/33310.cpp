// Title : Minimal Coprime
// Link  : https://www.acmicpc.net/problem/33310 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int l, r;
    cin >> l >> r;
    cout << max<int>(r - l, l == 1) << "\n";
  }

  return 0;
}