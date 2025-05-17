// Title : 몇개고?
// Link  : https://www.acmicpc.net/problem/27294 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t, s;
  cin >> t >> s;

  if (12 <= t && t <= 16 && s == 0) {
    cout << "320";
  } else {
    cout << "280";
  }

  return 0;
}
