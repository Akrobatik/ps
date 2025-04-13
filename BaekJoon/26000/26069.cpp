// Title : 붙임성 좋은 총총이
// Link  : https://www.acmicpc.net/problem/26069 
// Time  : 0 ms
// Memory: 2160 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  unordered_set<string> hs;
  hs.insert("ChongChong");

  int n;
  cin >> n;
  while (n--) {
    string s1, s2;
    cin >> s1 >> s2;
    if (hs.contains(s1) || hs.contains(s2)) {
      hs.insert(s1), hs.insert(s2);
    }
  }
  cout << hs.size();

  return 0;
}
