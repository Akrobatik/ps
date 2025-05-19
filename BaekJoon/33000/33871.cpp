// Title : 서로소 게임
// Link  : https://www.acmicpc.net/problem/33871 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  if (n & 1) {
    cout << "Soomin";
  } else {
    cout << "Song";
  }

  return 0;
}
