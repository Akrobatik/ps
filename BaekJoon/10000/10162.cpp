// Title : 전자레인지
// Link  : https://www.acmicpc.net/problem/10162
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int64_t n;
  cin >> n;
  if (n % 10 != 0) {
    cout << "-1";
    return 0;
  }
  int64_t a = n / 300;
  int64_t b = (n - a * 300) / 60;
  int64_t c = (n - a * 300 - b * 60) / 10;
  cout << a << " " << b << " " << c;

  return 0;
}
