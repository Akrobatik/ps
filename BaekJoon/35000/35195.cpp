// Title : Dralinpome
// Link  : https://www.acmicpc.net/problem/35195 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int cnt[256] = {};
  char c;
  while (cin >> c) ++cnt[c];

  int odd = 0;
  for (int i = 'a'; i <= 'z'; i++) odd += cnt[i] & 1;

  cout << (odd <= 1 ? "yes" : "no");

  return 0;
}