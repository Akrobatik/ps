#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  while (n--) {
    double x;
    cin >> x;
    cout << "$" << setprecision(2) << fixed << round(x * 80.0) / 100.0 << "\n";
  }

  return 0;
}
