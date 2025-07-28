// Title : 돌 게임
// Link  : https://www.acmicpc.net/problem/9655 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  cout << (n % 2 == 0 ? "CY" : "SK");

  return 0;
}
