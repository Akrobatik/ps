// Title : 괴짜 교수
// Link  : https://www.acmicpc.net/problem/11109
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int64_t d, n, s, p;
    cin >> d >> n >> s >> p;
    int64_t x = n * s;
    int64_t y = d + n * p;
    if (x == y) {
      cout << "does not matter\n";
    } else if (x < y) {
      cout << "do not parallelize\n";
    } else {
      cout << "parallelize\n";
    }
  }

  return 0;
}
