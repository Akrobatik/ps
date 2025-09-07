// Title : 숭고한에 어서오세요
// Link  : https://www.acmicpc.net/problem/34236 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, a, b;
  cin >> n >> a >> b;
  cout << a + (b - a) * n;

  return 0;
}
