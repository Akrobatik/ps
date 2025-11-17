// Title : 라면 끓여 먹자 야호
// Link  : https://www.acmicpc.net/problem/34687 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int64_t n, m;
  cin >> n >> m;
  cout << (n * 81 <= m * 100 ? "yaho" : "no");

  return 0;
}