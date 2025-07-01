// Title : 윷놀이
// Link  : https://www.acmicpc.net/problem/2490 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  for (int i = 0; i < 3; i++) {
    int cnt = 0;
    for (int j = 0; j < 4; j++) {
      int x;
      cin >> x;
      cnt += x;
    }
    cout << "DCBAE"[cnt] << "\n";
  }

  return 0;
}
