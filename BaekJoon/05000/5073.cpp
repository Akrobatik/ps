// Title : 삼각형과 세 변
// Link  : https://www.acmicpc.net/problem/5073 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int a, b, c;
  while (cin >> a >> b >> c && a && b && c) {
    int x[] = {a, b, c};
    sort(x, x + 3);

    if (x[0] + x[1] <= x[2]) {
      cout << "Invalid\n";
      continue;
    }

    if (x[0] == x[2]) {
      cout << "Equilateral\n";
      continue;
    }

    if (x[0] == x[1] || x[1] == x[2]) {
      cout << "Isosceles\n";
      continue;
    }

    cout << "Scalene\n";
  }

  return 0;
}
