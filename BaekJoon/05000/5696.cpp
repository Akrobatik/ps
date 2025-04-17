// Title : 숫자 세기
// Link  : https://www.acmicpc.net/problem/5696 
// Time  : 4 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

array<int, 10> Count(int n) {
  array<int, 10> cnts{};
  for (int i = 1; i <= n; i *= 10) {
    int x = n / (i * 10), y = (n / i) % 10, z = n - x * i * 10 - y * i;
    for (int j = 0; j < 10; j++) {
      if (j < y) {
        cnts[j] += (x + 1) * i;
      } else if (j == y) {
        cnts[j] += x * i + z + 1;
      } else {
        cnts[j] += x * i;
      }
    }
    cnts[0] -= i;
  }
  return cnts;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int a, b;
  while (cin >> a >> b && a && b) {
    auto ac = Count(a - 1), bc = Count(b);
    for (int i = 0; i < 10; i++) cout << bc[i] - ac[i] << " ";
    cout << "\n";
  }

  return 0;
}
