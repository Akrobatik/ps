// Title : 고령 멜빙 축제
// Link  : https://www.acmicpc.net/problem/34661 
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
    int n, m;
    cin >> n >> m;

    int nm = n * m, cnt = 0;
    char c;
    while (nm--) cin >> c, cnt += (c == '.');
    cout << ((cnt & 1) ? "sewon\n" : "pizza\n");
  }

  return 0;
}