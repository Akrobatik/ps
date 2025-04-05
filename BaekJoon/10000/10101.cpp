// Title : 삼각형 외우기
// Link  : https://www.acmicpc.net/problem/10101
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int a, b, c;
  cin >> a >> b >> c;
  if (a + b + c != 180) {
    cout << "Error";
  } else if (a == 60 && b == 60 && c == 60) {
    cout << "Equilateral";
  } else if (a == b || b == c || c == a) {
    cout << "Isosceles";
  } else {
    cout << "Scalene";
  }

  return 0;
}
