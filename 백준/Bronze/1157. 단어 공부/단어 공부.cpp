#include <bits/stdc++.h>

using namespace std;

int memo[256];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  cin >> s;
  for (auto c : s) {
    ++memo[c & 0xDF];
  }

  char ans;
  int maxx = 0;
  for (int i = 0; i < 256; i++) {
    if (maxx < memo[i]) {
      ans = i;
      maxx = memo[i];
    } else if (maxx == memo[i]) {
      ans = '?';
    }
  }
  cout << ans;

  return 0;
}
