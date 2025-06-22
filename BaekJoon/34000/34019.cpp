// Title : [G] Grounded Number
// Link  : https://www.acmicpc.net/problem/34019 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int64_t n;
  cin >> n;
  cout << ((n & 1) ? "No" : "Yes");

  return 0;
}
