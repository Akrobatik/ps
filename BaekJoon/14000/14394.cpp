// Title : 9-퍼즐
// Link  : https://www.acmicpc.net/problem/14394 
// Time  : 0 ms
// Memory: 2024 KB

#include <bits/stdc++.h>

using namespace std;

int GetId(char c) {
  if (c == 'B') return 0;
  if (c == 'G') return 1;
  if (c == 'Y') return 2;
  if (c == 'R') return 3;
  return 4;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int a[5] = {}, b[5] = {};

  string s1, s2;
  cin >> s1 >> s2;
  for (auto c : s1) ++a[GetId(c)];
  for (auto c : s2) ++b[GetId(c)];
  int sum = 0;
  for (int i = 0; i <= 3; i++) sum += abs(a[i] - b[i]);
  cout << sum / 2;

  return 0;
}
