// Title : A＋B － 5
// Link  : https://www.acmicpc.net/problem/10952
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  for (;;) {
    int a, b;
    cin >> a >> b;
    if (a == 0 && b == 0) break;
    cout << a + b << "\n";
  }

  return 0;
}
