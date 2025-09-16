// Title : 세금
// Link  : https://www.acmicpc.net/problem/20492 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  n /= 1000;
  cout << n * 780 << " " << n * 956;

  return 0;
}
