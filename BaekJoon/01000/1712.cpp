// Title : 손익분기점
// Link  : https://www.acmicpc.net/problem/1712
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int64_t a, b, c;
  cin >> a >> b >> c;
  if (b >= c) {
    cout << "-1";
    return 0;
  }
  int64_t d = c - b;
  cout << a / d + 1;

  return 0;
}
