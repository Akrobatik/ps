// Title : 결합
// Link  : https://www.acmicpc.net/problem/24533 
// Time  : 48 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  int64_t sum = 0, a = 0, b = 0;
  while (n--) {
    int64_t c, d;
    cin >> c >> d;
    sum += a * d + b * c;
    a += c, b += d;
  }
  cout << sum;

  return 0;
}