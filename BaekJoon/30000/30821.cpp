// Title : 별자리가 될 수 있다면
// Link  : https://www.acmicpc.net/problem/30821 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  int64_t x = 1;
  for (int i = 0; i < 5; i++) {
    x *= n - i;
    x /= i + 1;
  }
  cout << x;

  return 0;
}
