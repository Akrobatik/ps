// Title : 상수
// Link  : https://www.acmicpc.net/problem/2908 
// Time  : 0 ms
// Memory: 2024 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string s1, s2;
  cin >> s1 >> s2;
  reverse(s1.begin(), s1.end());
  reverse(s2.begin(), s2.end());
  int n1 = stoi(s1), n2 = stoi(s2);
  cout << max<int>(n1, n2);

  return 0;
}
