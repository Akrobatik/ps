#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int64_t a, b, c;
  while (cin >> a >> b >> c) {
    cout << max<int64_t>(b - a, c - b) - 1 << "\n";
  }

  return 0;
}
