// Title : 과목선택
// Link  : https://www.acmicpc.net/problem/11948
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int64_t sum = 0, m1 = INT_MAX, m2 = INT_MAX;
  for (int i = 0; i < 4; i++) {
    int64_t x;
    cin >> x;
    sum += x;
    m1 = min<int64_t>(m1, x);
  }
  for (int i = 0; i < 2; i++) {
    int64_t x;
    cin >> x;
    sum += x;
    m2 = min<int64_t>(m2, x);
  }
  cout << sum - m1 - m2;

  return 0;
}
