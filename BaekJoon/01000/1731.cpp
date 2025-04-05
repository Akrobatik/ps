// Title : 추론
// Link  : https://www.acmicpc.net/problem/1731
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, s1, s2, s3;
  cin >> n >> s1 >> s2 >> s3;
  if (s2 - s1 == s3 - s2) {
    cout << s1 + (s2 - s1) * n;
  } else {
    int64_t x = s1;
    while (n--) x = x * s2 / s1;
    cout << x;
  }


  return 0;
}
