#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int64_t a, b;
    cin >> a >> b;
    cout << (a / b) + (a % b != 0) << "\n";
  }

  return 0;
}
