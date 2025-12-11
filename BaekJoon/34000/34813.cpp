// Title : 공통교육과정
// Link  : https://www.acmicpc.net/problem/34813 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  char c;
  cin >> c;
  switch (c) {
    case 'F': {
      cout << "Foundation";
    } break;

    case 'C': {
      cout << "Claves";
    } break;

    case 'V': {
      cout << "Veritas";
    } break;

    case 'E': {
      cout << "Exploration";
    } break;
  }

  return 0;
}