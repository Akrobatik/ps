// Title : 소트인사이드
// Link  : https://www.acmicpc.net/problem/1427 
// Time  : 0 ms
// Memory: 2024 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  cin >> s;
  sort(s.begin(), s.end(), greater<>());
  cout << s;

  return 0;
}
