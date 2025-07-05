// Title : 랜덤 게임~
// Link  : https://www.acmicpc.net/problem/10943 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  mt19937 gen(random_device{}());
  cout << gen() % 10 + 1;

  return 0;
}
