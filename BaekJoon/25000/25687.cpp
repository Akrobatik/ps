// Title : 2차원
// Link  : https://www.acmicpc.net/problem/25687 
// Time  : 344 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  int n2 = n * n;
  for (int i = 0; i < n; i++) {
    int x = i * (n - 1) + n;
    for (int j = 0; j < n; j++) {
      cout << x << " ";
      if ((x += n) > n2) x -= n2;
    }
    cout << "\n";
  }

  return 0;
}
