// Title : 대각선
// Link  : https://www.acmicpc.net/problem/34346 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  cout << 2 - (n & 1);

  return 0;
}
