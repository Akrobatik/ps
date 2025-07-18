// Title : Building Pyramids
// Link  : https://www.acmicpc.net/problem/32585 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  int64_t sum = 0, val = 0;
  for (int i = 1; i <= n; i++) {
    val += i;
    sum += val;
  }
  cout << sum;

  return 0;
}
