// Title : 코드마스터 2023
// Link  : https://www.acmicpc.net/problem/28235 
// Time  : 0 ms
// Memory: 2024 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  cin >> s;
  switch (s[0]) {
    case 'S': {
      cout << "HIGHSCHOOL";
    } break;
    case 'C': {
      cout << "MASTER";
    } break;
    case '2': {
      cout <<  "0611";
    } break;
    case 'A': {
      cout << "CONTEST";
    } break;
  }

  return 0;
}
