// Title : 가희와 4시간의 벽 2
// Link  : https://www.acmicpc.net/problem/32776 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int a, b1, b2, b3;
  cin >> a >> b1 >> b2 >> b3;
  int b = b1 + b2 + b3;
  cout << (a <= b || a <= 240 ? "high speed rail" : "flight");

  return 0;
}