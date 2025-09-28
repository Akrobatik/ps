// Title : 초콜릿 우유가 좋아
// Link  : https://www.acmicpc.net/problem/34510 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int64_t h1, h2, h3, n;
  cin >> h1 >> h2 >> h3 >> n;

  int64_t h = h3 * n + h2 * ((n + 1) >> 1);
  if (n & 1) h += h1;
  cout << h;

  return 0;
}