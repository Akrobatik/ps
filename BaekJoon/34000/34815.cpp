// Title : $K+1$의 배수
// Link  : https://www.acmicpc.net/problem/34815 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int64_t n, k;
  cin >> n >> k;

  cout << (n == k && n % 2 == 1 ? "NO" : "YES");

  return 0;
}