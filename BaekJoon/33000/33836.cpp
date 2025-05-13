// Title : 벌집우주와 쿼리
// Link  : https://www.acmicpc.net/problem/33836 
// Time  : 24 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int x, y;
    cin >> x >> y;
    if (x >= 0 && y == 0) {
      cout << "0\n";
      continue;
    } 

    if (x < 0 && y > 0) {
      cout << "2\n";
      continue;
    }

    if (x < y && y < 0) {
      cout << "2\n";
      continue;
    }

    cout << "1\n";
  }

  return 0;
}
