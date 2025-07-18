// Title : 구구단표
// Link  : https://www.acmicpc.net/problem/32710 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  bool ok[101] = {};
  for (int i = 2; i <= 9; i++) {
    for (int j = 1; j <= 9; j++) {
      ok[i * j] = true;
    }
  }
  ok[1] = true;
  
  int n;
  cin >> n;
  cout << ok[n];

  return 0;
}