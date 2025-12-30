// Title : 所持金 (Money On Me)
// Link  : https://www.acmicpc.net/problem/33169 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int a, b;
  cin >> a >> b;
  cout << (a * 1000 + b * 10000);

  return 0;
}