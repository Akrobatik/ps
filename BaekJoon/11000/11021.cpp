// Title : A＋B － 7
// Link  : https://www.acmicpc.net/problem/11021
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    int a, b;
    cin >> a >> b;
    cout << "Case #" << i << ": " << a + b << "\n";
  }

  return 0;
}