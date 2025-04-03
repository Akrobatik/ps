#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int a, b;
  cin >> a >> b;
  cout << (a * b % 3 == 0 ? "YES" : "NO");
  return 0;
}
