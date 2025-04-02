#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string s1, s2;
  cin >> s1 >> s2;
  int64_t x1 = 0, x2 = 0;
  for (auto c : s1) x1 += (c - '0');
  for (auto c : s2) x2 += (c - '0');
  cout << x1 * x2;

  return 0;
}
