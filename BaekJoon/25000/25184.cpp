// Title : 동가수열 구하기
// Link  : https://www.acmicpc.net/problem/25184 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  int l = 1, r = n >> 1;
  for (int i = 0; i < n; i++) {
    cout << ((i & 1) ? l++ : ++r) << " ";
  }

  return 0;
}