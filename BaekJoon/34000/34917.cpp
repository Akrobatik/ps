// Title : M
// Link  : https://www.acmicpc.net/problem/34917 
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
    int n;
    cin >> n;
    int half = n >> 1;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cout << ((j == 0 || j + 1 == n) || (i <= half && abs(half - j) == half - i) ? '#' : '.');
      }
      cout << '\n';
    }
  }

  return 0;
}