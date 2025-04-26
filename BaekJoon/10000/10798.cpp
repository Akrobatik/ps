// Title : 세로읽기
// Link  : https://www.acmicpc.net/problem/10798 
// Time  : 0 ms
// Memory: 2024 KB

#include <bits/stdc++.h>

using namespace std;

string s[5];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  for (int i = 0; i < 5; i++) {
    cin >> s[i];
  }

  for (int i = 0; i < 15; i++) {
    for (int j = 0; j < 5; j++) {
      if (s[j].size() <= i) continue;
      cout << s[j][i];
    }
  }

  return 0;
}
