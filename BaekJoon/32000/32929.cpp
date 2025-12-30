// Title : UOS 문자열
// Link  : https://www.acmicpc.net/problem/32929 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n, --n;
  cout << "UOS"[n % 3];

  return 0;
}