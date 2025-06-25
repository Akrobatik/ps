// Title : 서로소 그래프 게임
// Link  : https://www.acmicpc.net/problem/34035 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    cout << (n == 2 ? "kang\n" : "chan\n");
  }

  return 0;
}
