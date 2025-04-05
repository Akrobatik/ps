// Title : 곱셈
// Link  : https://www.acmicpc.net/problem/1629
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int64_t ExpMod(int64_t a, int64_t b, int64_t c) {
  if (b == 1) return a % c;

  int64_t v1 = ExpMod(a, b / 2, c);
  int64_t v2 = (v1 * v1) % c;
  if (b % 2 == 0) return v2;
  return (v2 * a) % c;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int64_t a, b, c;
  cin >> a >> b >> c;
  cout << ExpMod(a, b, c) << endl;

  return 0;
}
