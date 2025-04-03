#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int64_t a0, b0, a1, b1;
  cin >> a0 >> b0 >> a1 >> b1;
  cout << min<int64_t>(a0 + b1, a1 + b0);

  return 0;
}
