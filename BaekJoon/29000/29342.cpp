// Title : Война клонов
// Link  : https://www.acmicpc.net/problem/29342 
// Time  : 8 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  int a = 0, b = 0;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    if (x & 1) {
      ++a;
    } else {
      ++b;
    }
  }
  cout << (int64_t)a * b;

  return 0;
}
