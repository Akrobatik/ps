// Title : A＋B － 8
// Link  : https://www.acmicpc.net/problem/11022
// Time  : 0 ms
// Memory: 2376 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    int64_t a, b;
    cin >> a >> b;
    printf("Case #%d: %d + %d = %d\n", i, a, b, a + b);
  }

  return 0;
}
