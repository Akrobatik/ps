// Title : Character Frequencies
// Link  : https://www.acmicpc.net/problem/29847 
// Time  : 0 ms
// Memory: 2024 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  map<char, int> memo;
  int n;
  cin >> n;
  char c;
  while (cin >> c) ++memo[c];

  for (auto [c, cnt] : memo) {
    cout << c << " " << cnt << "\n";
  }

  return 0;
}
