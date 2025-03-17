#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int64_t n, m;
  cin >> n >> m;
  int64_t sum = -n;
  while (n--) {
    int64_t x;
    cin >> x;
    sum += x;
  }
  cout << (m <= sum ? "DIMI" : "OUT");

  return 0;
}
