// Title : Bob부 멍충이
// Link  : https://www.acmicpc.net/problem/34009 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  cout << ((n & 1) ? "Bob" : "Alice");

  return 0;
}
