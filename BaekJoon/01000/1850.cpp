// Title : 최대공약수
// Link  : https://www.acmicpc.net/problem/1850
// Time  : 4 ms
// Memory: 6904 KB

#include <bits/stdc++.h>

using namespace std;

int64_t GCD(int64_t a, int64_t b) {
  while (b) a %= b, swap(a, b);
  return a;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int64_t a, b;
  cin >> a >> b;
  string s(GCD(a, b), '1');
  cout << s;

  return 0;
}
