// Title : 1로 만들기
// Link  : https://www.acmicpc.net/problem/1463 
// Time  : 12 ms
// Memory: 6904 KB

#include <bits/stdc++.h>

using namespace std;

constexpr int kMax = 1e6;

bool memo[kMax + 1];
int vec[kMax];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  auto b = vec, e = vec;
  *e++ = 1;
  for (int i = 0;; i++) {
    int nv = e - b;
    while (nv--) {
      int x = *b++;
      if (x == n) {
        cout << i;
        return 0;
      }

      for (auto nxt : {x + 1, x * 2, x * 3}) {
        if (nxt <= kMax && !memo[nxt]) {
          memo[nxt] = true;
          *e++ = nxt;
        }
      }
    }
  }

  return 0;
}
