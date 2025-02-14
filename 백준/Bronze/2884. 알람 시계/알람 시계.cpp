#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int h, m;
  cin >> h >> m;
  m += (h * 60) + (24 * 60 - 45);
  h = (m / 60) % 24;
  m %= 60;
  cout << h << " " << m;

  return 0;
}
