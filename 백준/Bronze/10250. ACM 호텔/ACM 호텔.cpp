#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int h, w, n;
    cin >> h >> w >> n;
    --n;
    int y = (n % h) + 1;
    int x = (n / h) + 1;
    cout << y << setw(2) << setfill('0') << x << "\n";
  }

  return 0;
}
