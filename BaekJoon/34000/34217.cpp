// Title : 찾아오시는 길
// Link  : https://www.acmicpc.net/problem/34217 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int a, b, c, d;
  cin >> a >> b >> c >> d;

  int ac = a + c, bd = b + d;
  cout << (ac < bd ? "Hanyang Univ." : (ac > bd ? "Yongdap" : "Either"));

  return 0;
}
