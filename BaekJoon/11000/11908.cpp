// Title : 카드
// Link  : https://www.acmicpc.net/problem/11908
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  int64_t sum = 0, maxx = 0;
  while (n--) {
    int64_t x;
    cin >> x;
    sum += x;
    if (maxx < x) maxx = x;
  }
  cout << sum - maxx;

  return 0;
}
