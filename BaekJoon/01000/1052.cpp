// Title : 물병
// Link  : https://www.acmicpc.net/problem/1052
// Time  : 0 ms
// Memory: 2208 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  uint32_t n, k;
  cin >> n >> k;
  bitset<32> b(n);

  uint32_t result = 0;
  if (b.count() > k) {
    int nn = 0;
    uint32_t v = 0;
    for (int i = 31; i >= 0; i--) {
      if (b.test(i)) {
        if (++nn == k) {
          v += (uint32_t)pow(2, i + 1);
          result = v - n;
          break;
        } else {
          v += (uint32_t)pow(2, i);
        }
      }
    }
  }

  cout << result << endl;

  return 0;
}