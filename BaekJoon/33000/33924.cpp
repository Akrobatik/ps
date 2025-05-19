// Title : 신묘마루의 요술망치
// Link  : https://www.acmicpc.net/problem/33924 
// Time  : 0 ms
// Memory: 2024 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, k;
  string s;
  cin >> n >> m >> k >> s;

  --n, --m;
  for (auto c : s) {
    switch (c) {
      case 'A': {
        n = (n + 2) % 4;
      } break;
      case 'B': {
        n ^= 1, m ^= 1;
      } break;
      case 'C': {
        n = (n + 1) % 4;
        n ^= 1, m ^= 1;
        n = (n + 3) % 4;
      } break;
      case 'D': {
        if (m == 0) {
          if (n == 0) {
            m = 1;
          } else {
            --n;
          }
        } else {
          if (n == 3) {
            m = 0;
          } else {
            ++n;
          }
        }
      } break;
    }
  }
  cout << n + 1 << " " << m + 1;

  return 0;
}
