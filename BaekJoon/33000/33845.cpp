// Title : PNUPC에 한 번도 빠지지 않고 출연한 산지니가 새삼 대단하다고 느껴지네
// Link  : https://www.acmicpc.net/problem/33845 
// Time  : 0 ms
// Memory: 2168 KB

#include <bits/stdc++.h>

using namespace std;


int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string s1, s2;
  cin >> s1 >> s2;

  bool check[256] = {};
  for (auto c : s1) check[c] = true;

  for (auto c : s2) {
    if (check[c]) continue;
    cout << c;
  }

  return 0;
}
