// Title : 장기
// Link  : https://www.acmicpc.net/problem/1846 
// Time  : 4 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  if (n == 3) {
    cout << "-1";
    return 0;
  }

  int h1 = n >> 1, h2 = h1 + 1;
  cout << h1 << "\n";
  for (int i = 1; i <= n; i++) {
    if (i == h1 || i == h2) continue;
    cout << i << "\n";
  }
  cout << h2;

  return 0;
}
