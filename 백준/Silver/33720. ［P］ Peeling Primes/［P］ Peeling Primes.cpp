#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int64_t n;
  cin >> n;
  int64_t d = 2, rt = (int64_t)sqrtl((long double)n);
  while (d <= rt && n % d != 0) ++d;
  cout << (d > rt ? 1 : ((n - d) >> 1) + 1);

  return 0;
}
