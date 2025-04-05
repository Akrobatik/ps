// Title : 별 찍기 － 2
// Link  : https://www.acmicpc.net/problem/2439
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < n; j++) {
      cout << (j < n - i ? " " : "*");
    }
    cout << "\n";
  }

  return 0;
}
