#include <bits/stdc++.h>

using namespace std;

int64_t Round(int64_t n, int64_t d) {
  int64_t quot = n / d, rem = n % d;
  return quot + (rem >= (d >> 1) + (d & 1));
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  int64_t r = 0;
  while (n--) {
    int64_t a, b, p;
    cin >> a >> b >> p;
    r = max<int64_t>(r, Round(a * p + b * r, a + b));
  }
  cout << r;

  return 0;
}
