// Title : 자동완성
// Link  : https://www.acmicpc.net/problem/24883 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  char c;
  cin >> c;
  if (tolower(c) == 'n') {
    cout << "Naver D2";
  } else {
    cout << "Naver Whale";
  }

  return 0;
}