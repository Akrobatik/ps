#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  uint8_t b[10];
  memset(b, 0, sizeof(b));

  int ch;
  int n;
  cin >> ch;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int v;
    cin >> v;
    b[v] = 1;
  }

  int result = abs(ch - 100);
  for (int i = 0; i < 1000000; i++) {
    int v = i;
    int digits = 0;
    bool ok = true;
    do {
      if (b[v % 10]) {
        ok = false;
        break;
      }
      digits++;
    } while (v /= 10);

    if (ok) {
      v = abs(ch - i) + digits;
      if (result > v) result = v;
    }
  }

  cout << result << endl;

  return 0;
}