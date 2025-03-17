#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    char c;
    int64_t a, b, d;
    cin >> a >> b;

    if (a > b) {
      d = a - b;
      c = 'A';
    } else {
      swap(a, b);
      d = a - b;
      c = 'B';
    }

    if (a == b) {
      cout << "0\n";
      continue;
    }
    if (d & 1) {
      cout << "-1\n";
      continue;
    }

    d >>= 1;
    int cnt = (a & d) == d ? 1 : 2;
    cout << cnt << "\n";
    for (int i = 0; i < cnt; i++) {
      cout << c << " " << d << "\n";
    }
  }

  return 0;
}
