#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int64_t a, b, c;
  cin >> a >> b >> c;
  if (b >= c) {
    cout << "-1";
    return 0;
  }
  int64_t d = c - b;
  cout << a / d + 1;

  return 0;
}
