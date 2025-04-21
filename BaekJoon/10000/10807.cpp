// Title : 개수 세기
// Link  : https://www.acmicpc.net/problem/10807 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int cnt[201] = {};

  int n;
  cin >> n;
  while (n--) {
    int x;
    cin >> x;
    ++cnt[x + 100];
  }
  int v;
  cin >> v;
  cout << cnt[v + 100];

  return 0;
}
