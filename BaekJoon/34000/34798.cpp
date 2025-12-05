// Title : Missed Alarm
// Link  : https://www.acmicpc.net/problem/34798 
// Time  : 0 ms
// Memory: 2024 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string s1, s2;
  cin >> s1 >> s2;
  cout << (s1 > s2 ? "NO" : "YES");

  return 0;
}