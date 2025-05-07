// Title : A/B - 2
// Link  : https://www.acmicpc.net/problem/15792 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int a, b;
  cin >> a >> b;
  cout << a / b << ".";
  for (int i = 0; i < 1000; i++) {
    a = (a % b) * 10;
    cout << a / b; 
  }

  return 0;
}
