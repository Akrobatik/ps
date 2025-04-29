// Title : Рыцарский щит
// Link  : https://www.acmicpc.net/problem/20490 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int a, b, c, d, e, f;
  cin >> a >> b >> c >> d >> e >> f;
  int g = min<int>(max<int>({a, b, c}), max<int>({d, e, f}));
  cout << a + b + c + d + e + f - (g << 1);

  return 0;
}
