// Title : 민규의 서카디안 리듬
// Link  : https://www.acmicpc.net/problem/34400 
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
    x %= 25;
    cout << (0 <= x && x < 17 ? "ONLINE\n" : "OFFLINE\n");
  }

  return 0;
}