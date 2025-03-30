#include <bits/stdc++.h>

using namespace std;

constexpr int64_t kMax = 1e18;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int64_t a, b;
  cin >> a >> b;
  int64_t aa = a, bb = b;
  for (int64_t bit = 1; bit <= kMax; bit <<= 1) {
    if ((aa & bit) != (bb & bit)) continue;
    if (a <= (aa ^ bit) && (aa ^ bit) <= b) {
      aa ^= bit;
    } else if (a <= (bb ^ bit) && (bb ^ bit) <= b) {
      bb ^= bit;
    }
  }
  cout << aa << " " << bb;

  return 0;
}
