// Title : $A ＋ B － C$
// Link  : https://www.acmicpc.net/problem/31403
// Time  : 0 ms
// Memory: 2024 KB

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
