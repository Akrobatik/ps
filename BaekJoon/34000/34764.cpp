// Title : 고양이 게임
// Link  : https://www.acmicpc.net/problem/34764 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  n %= 4;
  cout << (n == 2 || n == 3 ? "duck" : "goose");

  return 0;
}