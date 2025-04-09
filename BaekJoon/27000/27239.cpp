// Title : Шахматная доска
// Link  : https://www.acmicpc.net/problem/27239 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  --n;
  int quot = n / 8, rem = n % 8;
  cout << (char)(rem + 'a') << (char)(quot + '1');

  return 0;
}
