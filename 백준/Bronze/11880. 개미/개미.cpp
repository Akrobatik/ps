#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int64_t a, b, c;
    cin >> a >> b >> c;
    cout << min<int64_t>({a * a + (b + c) * (b + c), b * b + (a + c) * (a + c), c * c + (b + a) * (b + a)}) << "\n";
  }

  return 0;
}
