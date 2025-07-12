// Title : :chino_shock:
// Link  : https://www.acmicpc.net/problem/27310 
// Time  : 0 ms
// Memory: 2024 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  cin >> s;
  int sum = 0;
  for (auto c : s) {
    if (c == '_') {
      sum += 6;
    } else if (c == ':') {
      sum += 2;
    } else {
      sum += 1;
    }
  }
  cout << sum;

  return 0;
}