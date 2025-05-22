// Title : 여우 사인
// Link  : https://www.acmicpc.net/problem/14709 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  if (n != 3) {
    cout << "Woof-meow-tweet-squeek";
    return 0;
  }

  bool check[3] = {};
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    if (a > b) swap(a, b);

    bool ok = false;
    if (a == 1) {
      if (b == 3 && !check[0]) {
        ok = check[0] = true;
      } else if (b == 4 && !check[1]) {
        ok = check[1] = true;
      }
    } else if (a == 3 && b == 4 && !check[2]) {
      ok = check[2] = true;
    }

    if (!ok) {
      cout << "Woof-meow-tweet-squeek";
      return 0;
    }
  }
  cout << "Wa-pa-pa-pa-pa-pa-pow!";

  return 0;
}
