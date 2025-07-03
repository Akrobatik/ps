// Title : 마작에서 가장 어려운 것
// Link  : https://www.acmicpc.net/problem/33049 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int a, b, c;
  cin >> a >> b >> c;
  int n = a + b + c;

  for (int i = (a + 2) / 3; i * 3 + b <= n; i++) {
    int r = n - i * 3;
    if (r % 4) continue;
    int j = r / 4;
    cout << i << " " << j;
    return 0;
  }
  cout << "-1";

  return 0;
}
