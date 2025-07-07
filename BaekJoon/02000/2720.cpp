// Title : 세탁소 사장 동혁
// Link  : https://www.acmicpc.net/problem/2720 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int table[4] = {25, 10, 5, 1};

  int t;
  cin >> t;
  while (t--) {
    int x;
    cin >> x;
    for (int i = 0; i < 4; i++) {
      int c = x / table[i];
      x -= c * table[i];
      cout << c << " ";
    }
    cout << "\n";
  }

  return 0;
}
