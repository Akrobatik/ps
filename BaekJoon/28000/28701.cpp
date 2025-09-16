// Title : 세제곱의 합
// Link  : https://www.acmicpc.net/problem/28701 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int64_t n;
  cin >> n;
  int64_t x = n * (n + 1) / 2;
  cout << x << "\n"
       << x * x << "\n"
       << x * x << "\n";

  return 0;
}
