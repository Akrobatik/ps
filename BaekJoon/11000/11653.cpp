// Title : 소인수분해
// Link  : https://www.acmicpc.net/problem/11653
// Time  : 80 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int64_t n;
  cin >> n;
  for (int i = 2; n != 1; i++) {
    while (n % i == 0) {
      cout << i << "\n";
      n /= i;
    }
  }

  return 0;
}
