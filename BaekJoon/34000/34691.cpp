// Title : 대전과학고등학교를 사랑하십니까?
// Link  : https://www.acmicpc.net/problem/34691 
// Time  : 0 ms
// Memory: 2024 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  while (cin >> s) {
    switch (s[0]) {
      case 'a': {
        cout << "Panthera tigris\n";
      } break;

      case 't': {
        cout << "Pinus densiflora\n";
      } break;

      case 'f': {
        cout << "Forsythia koreana\n";
      } break;
    }
  }

  return 0;
}