// Title : Bus Assignment
// Link  : https://www.acmicpc.net/problem/32800 
// Time  : 24 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int64_t x = 0, maxx = 0;

  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    x += b - a;
    maxx = max<int64_t>(maxx, x);
  }
  cout << maxx;

  return 0;
}
