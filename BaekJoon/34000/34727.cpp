// Title : 큐브 채우기
// Link  : https://www.acmicpc.net/problem/34727 
// Time  : 16 ms
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
    cout << (n & 1) << "\n";
  }

  return 0;
}