// Title : 추석은 언제나 좋아
// Link  : https://www.acmicpc.net/problem/34750 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int64_t n;
  cin >> n;

  int64_t m = n / 20;
  if (n >= 1000000) {
    cout << m * 4 << " " << m * 16;
  } else if (n >= 500000) {
    cout << m * 3 << " " << m * 17;
  } else if (n >= 100000) {
    cout << m * 2 << " " << m * 18;
  } else {
    cout << m * 1 << " " << m * 19;
  }

  return 0;
}