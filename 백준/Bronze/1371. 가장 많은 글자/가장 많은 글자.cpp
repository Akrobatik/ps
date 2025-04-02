#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int memo[26] = {};
  int maxx = 0;
  char c;
  while (cin >> c) {
    if (isalpha(c)) {
      maxx = max<int>(maxx, ++memo[c - 'a']);
    }
  }

  for (int i = 0; i < 26; i++) {
    if (memo[i] != maxx) continue;
    cout << (char)(i + 'a');
  }

  return 0;
}
