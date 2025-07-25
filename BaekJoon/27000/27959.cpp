// Title : 초코바
// Link  : https://www.acmicpc.net/problem/27959 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  cout << (n * 100 >= m ? "Yes" : "No");

  return 0;
}