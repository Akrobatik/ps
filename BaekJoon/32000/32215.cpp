// Title : 코드마스터 2024
// Link  : https://www.acmicpc.net/problem/32215 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, k;
  cin >> n >> m >> k;

  cout << (k + (n != k)) * m;

  return 0;
}
