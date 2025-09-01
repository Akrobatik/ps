// Title : 팬들에게 둘러싸인 홍준
// Link  : https://www.acmicpc.net/problem/14581 
// Time  : 0 ms
// Memory: 2380 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  cin >> s;
  cout << format(":fan::fan::fan:\n:fan::{}::fan:\n:fan::fan::fan:", s);

  return 0;
}