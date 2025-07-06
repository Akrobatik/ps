// Title : 수라도
// Link  : https://www.acmicpc.net/problem/34043 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  cout << ((n <= 3 && (n & 1) == 1) ? "NO" : "YES");

  return 0;
}