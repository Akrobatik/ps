// Title : A → B
// Link  : https://www.acmicpc.net/problem/16953
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int Count(int64_t a, int64_t b, int c) {
  if (a == b) return c;
  if (a > b) return -1;
  return max<int>(
      Count(a * 10 + 1, b, c + 1),
      Count(a << 1, b, c + 1));
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int64_t a, b;
  cin >> a >> b;
  cout << Count(a, b, 1) << endl;

  return 0;
}
