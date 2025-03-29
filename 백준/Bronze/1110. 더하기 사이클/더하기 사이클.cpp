#include <bits/stdc++.h>

using namespace std;

int Calc(int n) {
  int l = n % 10, r = (l + n / 10) % 10;
  return l * 10 + r;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  int nxt = Calc(n), cnt = 1;
  while (nxt != n) {
    nxt = Calc(nxt);
    ++cnt;
  }
  cout << cnt;

  return 0;
}
