// Title : 저녁 메뉴 월드컵
// Link  : https://www.acmicpc.net/problem/34848 
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
    int x;
    cin >> x;

    int cnt = 0;
    while (x > 1) {
      cnt += x & 1;
      x = (x + 1) >> 1;
    }
    cout << cnt << "\n";
  }

  return 0;
}