// Title : 인버전의 기댓값
// Link  : https://www.acmicpc.net/problem/34840 
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
    cout << "0";
    return 0;
  }

  long double e = 0.5L;
  for (int i = 2; i < n; i++) {
    e = e * (long double)(i + 1) / (long double)(i - 1);
  }
  cout << setprecision(9) << fixed << e;

  return 0;
}