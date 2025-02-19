#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  uint64_t k;
  cin >> k;
  cout << (bitset<64>(k - 1).count() & 1ull);

  return 0;
}
