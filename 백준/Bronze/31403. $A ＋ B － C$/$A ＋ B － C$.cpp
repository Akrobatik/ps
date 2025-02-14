#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string a, b;
  int c;
  cin >> a >> b >> c;
  cout << stoi(a) + stoi(b) - c << "\n"
       << stoi(a + b) - c;

  return 0;
}
