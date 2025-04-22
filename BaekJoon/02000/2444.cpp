// Title : 별 찍기 - 7
// Link  : https://www.acmicpc.net/problem/2444 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  int m = (n << 1) - 1;
  for (int i = 0; i < m; i++) {
    int l = abs(n - i - 1), r = m - l;
    for (int j = 0; j < l; j++) cout << ' ';
    for (int j = l; j < r; j++) cout << '*';
    if (i + 1 != m) cout << '\n';
  }

  return 0;
}
