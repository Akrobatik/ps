#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int64_t a, b, c;
  cin >> a >> b >> c;
  int64_t maxx = max<int64_t>({a, b, c});
  cout << min<int64_t>(a + b + c, ((a + b + c - maxx) << 1) - 1);

  return 0;
}
