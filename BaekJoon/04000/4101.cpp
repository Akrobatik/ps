// Title : 크냐?
// Link  : https://www.acmicpc.net/problem/4101 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int a, b;
  while (cin >> a >> b && a && b) {
    cout << (a > b ? "Yes\n" : "No\n");
  }

  return 0;
}
