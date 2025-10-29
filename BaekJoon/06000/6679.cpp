// Title : 싱기한 네자리 숫자
// Link  : https://www.acmicpc.net/problem/6679 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

constexpr int kBase[] = {10, 12, 16};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  for (int i = 1000; i < 10000; i++) {
    int x = 0;
    bool ok = true;
    for (auto b : kBase) {
      int v = i, s = 0;
      while (v > 0) s += v % b, v /= b;
      if (x && x != s) {
        ok = false;
        break;
      }
      x = s;
    }
    if (ok) cout << i << "\n";
  }

  return 0;
}