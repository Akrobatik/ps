#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, r, c;
  cin >> n >> r >> c;
  bitset<32> br(r);
  bitset<32> bc(c);

  int result = 0;
  for (int i = 0; i < n; i++) {
    int v = (br.test(i) ? 2 : 0) + (bc.test(i) ? 1 : 0);
    result |= v * (1 << i * 2);
  }
  cout << result << endl;

  return 0;
}