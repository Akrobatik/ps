// Title : T 타일링
// Link  : https://www.acmicpc.net/problem/34516 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

constexpr char kUnit[4][4] = {
    {'a', 'a', 'a', 'b'},
    {'d', 'a', 'b', 'b'},
    {'d', 'd', 'c', 'b'},
    {'d', 'c', 'c', 'c'},
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  if (n % 4) {
    cout << "-1";
    return 0;
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << kUnit[i & 3][j & 3];
    }
    cout << "\n";
  }

  return 0;
}