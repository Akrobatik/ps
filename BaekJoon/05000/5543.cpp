// Title : 상근날드
// Link  : https://www.acmicpc.net/problem/5543 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int a, b, c, d, e;
  cin >> a >> b >> c >> d >> e;
  cout << min<int>({a, b, c}) + min<int>(d, e) - 50;

  return 0;
}
