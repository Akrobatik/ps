// Title : binary는 호남선
// Link  : https://www.acmicpc.net/problem/23306 
// Time  : 4 ms
// Memory: 13820 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  int x, y;
  cout << "? 1" << endl;
  cin >> x;
  cout << "? " << n << endl;
  cin >> y;

  cout << "! " << ((x < y) - (x > y));

  return 0;
}