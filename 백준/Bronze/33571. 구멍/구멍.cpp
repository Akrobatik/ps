#include <bits/stdc++.h>

using namespace std;

constexpr const char* kOne = "ADOPQRabdegopq@";
constexpr const char* kTwo = "B";

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int memo[256] = {};
  for (int i = 0; kOne[i]; i++) memo[kOne[i]] = 1;
  for (int i = 0; kTwo[i]; i++) memo[kTwo[i]] = 2;
  string s;
  getline(cin, s);
  int64_t ans = 0;
  for (auto c : s) {
    ans += memo[c];
  }
  cout << ans;

  return 0;
}
