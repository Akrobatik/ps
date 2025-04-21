// Title : 영수증
// Link  : https://www.acmicpc.net/problem/25304 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int x, n, sum = 0;
  cin >> x >> n;
  while (n--) {
    int a, b;
    cin >> a >> b;
    sum += a * b;
  }

  cout << (sum == x ? "Yes" : "No");

  return 0;
}
