#include <bits/stdc++.h>

using namespace std;

int memo[10];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int a, b, c;
  cin >> a >> b >> c;
  int v = a * b * c;
  while (v) {
    auto dv = div(v, 10);
    ++memo[dv.rem];
    v = dv.quot;
  }

  for (auto e : memo) cout << e << "\n";

  return 0;
}
