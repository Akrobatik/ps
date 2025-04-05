// Title : 잃어버린 괄호
// Link  : https://www.acmicpc.net/problem/1541
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  bool minus = false;
  int ans;
  cin >> ans;
  char op;
  while (cin >> op && (op == '-' || op == '+')) {
    int v;
    cin >> v;
    if (!minus && op == '-') minus = true;
    ans += v * (minus ? -1 : 1);
  }
  cout << ans;

  return 0;
}
