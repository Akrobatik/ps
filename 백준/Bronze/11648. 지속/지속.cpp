#include <bits/stdc++.h>

using namespace std;

int64_t Calc(int64_t x) {
  string s = to_string(x);
  int64_t nxt = 1;
  for (auto c : s) nxt *= c - '0';
  return nxt;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int64_t n;
  cin >> n;
  for (int i = 0;; i++) {
    if (n < 10) {
      cout << i;
      return 0;
    }
    n = Calc(n);
  }

  return 0;
}
