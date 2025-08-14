// Title : $A$의 배수
// Link  : https://www.acmicpc.net/problem/34124 
// Time  : 264 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n, a;
    cin >> n >> a;
    cout << ((n & 1) || n == 2 ? "O\n" : "I\n");
  }

  return 0;
}
