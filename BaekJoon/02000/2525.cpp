// Title : 오븐 시계
// Link  : https://www.acmicpc.net/problem/2525 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int a, b, c;
  cin >> a >> b >> c;
  int t = a * 60 + b + c;
  cout << (t / 60) % 24 << " " << t % 60;

  return 0;
}
