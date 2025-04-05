// Title : 언더프라임
// Link  : https://www.acmicpc.net/problem/1124
// Time  : 0 ms
// Memory: 2508 KB

#include <bits/stdc++.h>

using namespace std;

int cnts[100001];
bool memo[100001];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  memo[0] = memo[1] = true;
  for (int64_t i = 2; i <= 100000; i++) {
    if (memo[i]) continue;
    for (int j = (i << 1); j <= 100000; j += i) memo[j] = true, ++cnts[j];

    for (int64_t j = i * i; j <= 100000; j *= i) {
      for (int k = j; k <= 100000; k += j) ++cnts[k];
    }
  }

  int a, b;
  cin >> a >> b;
  int ans = 0;
  for (int i = a; i <= b; i++) ans += (!memo[cnts[i]]);
  cout << ans;

  return 0;
}
