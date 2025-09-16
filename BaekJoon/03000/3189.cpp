// Title : tomo
// Link  : https://www.acmicpc.net/problem/3189 
// Time  : 0 ms
// Memory: 2264 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int64_t a, b, c;
  cin >> a >> b >> c;

  int64_t x = 10;
  while (x <= c) x *= 10;

  vector<bool> used(x);
  for (int64_t i = 1, v = a * b % x; !used[v]; i++, v = v * b % x) {
    used[v] = true;
    if (v == c) {
      cout << i;
      return 0;
    }
  }
  cout << "NIKAD";

  return 0;
}
