// Title : A+B - 10 (제1편)
// Link  : https://www.acmicpc.net/problem/30917 
// Time  : 4 ms
// Memory: 13676 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  auto Find = [](char c) {
    for (int i = 1; i <= 9; i++) {
      cout << "? " << c << " " << i << endl;
      int res;
      cin >> res;
      if (res) return i;
    }
    assert(0);
  };

  int a = Find('A'), b = Find('B');
  cout << "! " << a + b << endl;

  return 0;
}