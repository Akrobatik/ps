// Title : 케이크(?) 자르기
// Link  : https://www.acmicpc.net/problem/14445 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int64_t n;
  cin >> n;

  if (n == 1) {
    cout << "0";
  } else {
    cout << (n >> 1) + (n & 1);
  }

  return 0;
}
