// Title : SW 수열 구하기
// Link  : https://www.acmicpc.net/problem/28065 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  int l = 1, r = n;
  for (int i = 0; i < n; i++) {
    cout << ((i & 1) ? r-- : l++) << " ";
  }

  return 0;
}