// Title : High Towers
// Link  : https://www.acmicpc.net/problem/33785 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int64_t n;
  cin >> n;
  cout << n * (n + 1) * (n + 2) / 6;

  return 0;
}
