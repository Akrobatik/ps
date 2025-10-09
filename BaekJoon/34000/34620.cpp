// Title : 군꺾문자열
// Link  : https://www.acmicpc.net/problem/34620 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int a, b;
  cin >> a >> b;

  if (!has_single_bit((uint32_t)b)) {
    cout << "-1";
    return 0;
  }

  bitset<32> bits(a);
  for (int i = 0; i < 30; i++) {
    if (bits.test(i)) cout << 'G';
    if ((1 << i) < b) cout << 'K';
  }

  return 0;
}
