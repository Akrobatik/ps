// Title : 이상한 기호
// Link  : https://www.acmicpc.net/problem/15964 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int64_t a, b;
  cin >> a >> b;
  cout << (a + b) * (a - b);

  return 0;
}