#include <bits/stdc++.h>

using namespace std;

bool Check(int v) {
  int cnt = 3;
  while (v) {
    auto dv = div(v, 10);
    if (dv.rem == 6) {
      if (--cnt == 0) return true;
    } else {
      cnt = 3;
    }
    v = dv.quot;
  }
  return false;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  int v = 666;
  while (n) {
    if (Check(v++)) --n;
  }
  cout << --v;

  return 0;
}
