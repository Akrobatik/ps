// Title : 더하기 3
// Link  : https://www.acmicpc.net/problem/11023
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int64_t sum = 0, n;
  while (cin >> n) sum += n;
  cout << sum;

  return 0;
}
