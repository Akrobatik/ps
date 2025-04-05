// Title : 한수
// Link  : https://www.acmicpc.net/problem/1065 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<int> arr;
  arr.reserve(n);
  for (int i = 1; i <= n; i++) {
    if (i < 100) {
      arr.push_back(i);
    } else {
      bool ok = true;
      int x = i % 10, y = (i / 10) % 10, z = i / 100;
      if (z == 10) continue;
      if (x + z == (y << 1)) arr.push_back(i);
    }
  }
  cout << arr.size();

  return 0;
}
