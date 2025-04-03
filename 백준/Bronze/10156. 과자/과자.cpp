#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int64_t k, n, m;
  cin >> k >> n >> m;
  cout << max<int64_t>(k * n - m, 0);

  return 0;
}
