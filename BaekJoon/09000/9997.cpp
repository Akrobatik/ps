// Title : 폰트
// Link  : https://www.acmicpc.net/problem/9997 
// Time  : 536 ms
// Memory: 2024 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<bitset<32>> arr(n);
  for (auto& e : arr) {
    string s;
    cin >> s;
    for (auto c : s) e.set(c - 'a');
  }

  int ans = 0;
  int limit = 1 << n;
  for (int b = 1; b < limit; b++) {
    int x = b;
    bitset<32> cnt;
    while (x) {
      int lsb = x & (-x);
      cnt |= arr[countr_zero((uint32_t)lsb)];
      x -= lsb;
    }

    ans += (cnt.count() == 26);
  }
  cout << ans;

  return 0;
}
