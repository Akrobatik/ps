// Title : 구구단
// Link  : https://www.acmicpc.net/problem/2739
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  for (int i = 1; i <= 9; i++) {
    cout << n << " * " << i << " = " << n * i << "\n";
  }

  return 0;
}
