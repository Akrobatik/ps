// Title : 주사위 피라미드
// Link  : https://www.acmicpc.net/problem/33965 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int64_t n;
  cin >> n;
  cout << (n * (n + 1) / 2) * 35;

  return 0;
}
