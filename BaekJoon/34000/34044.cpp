// Title : 인간도
// Link  : https://www.acmicpc.net/problem/34044 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  if (n == 1) {
    cout << "-1";
    return 0;
  }

  if (n & 1) {
    cout << "434379";
    n -= 3;
  }
  for (int i = 0; i < n; i += 2) {
    cout << "3773";
  }

  return 0;
}