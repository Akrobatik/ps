// Title : ！밀비 급일
// Link  : https://www.acmicpc.net/problem/11365
// Time  : 0 ms
// Memory: 2024 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  while (getline(cin, s) && s.compare("END") != 0) {
    for (auto c : views::reverse(s)) cout << c;
    cout << "\n";
  }

  return 0;
}
