// Title : 선물 전달
// Link  : https://www.acmicpc.net/problem/1947 
// Time  : 4 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

constexpr int kMod = 1e9;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  int64_t cur = 1;
  for (int i = 1, j = -1; i <= n; i++, j = -j) {
    cur = (cur * i + j) % kMod;
    if (cur < 0) cur += kMod;
  }
  cout << cur;

  return 0;
}