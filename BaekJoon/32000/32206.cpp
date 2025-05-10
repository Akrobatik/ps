// Title : 아보와 킨텍스
// Link  : https://www.acmicpc.net/problem/32206 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int64_t n;
  cin >> n;
  cout << (n + 1) * 26 - n;

  return 0;
}
