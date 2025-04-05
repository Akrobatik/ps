// Title : 뜨거운 붕어빵
// Link  : https://www.acmicpc.net/problem/11945
// Time  : 0 ms
// Memory: 2024 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  while (n--) {
    string s;
    cin >> s;
    for (auto c : views::reverse(s)) cout << c;
    cout << "\n";
  }

  return 0;
}
