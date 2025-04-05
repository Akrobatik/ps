// Title : 2＾3은？
// Link  : https://www.acmicpc.net/problem/33614
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
    int p, q, r;
    cin >> p >> q >> r;
    cout << (p - 1) + min<int>(q, r) << "\n";
  }

  return 0;
}
