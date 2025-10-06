// Title : 동전 분배
// Link  : https://www.acmicpc.net/problem/1943 
// Time  : 268 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

constexpr int kMax = 5e4;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  while (cin >> n) {
    bitset<kMax + 1> memo;
    memo.set(0);
    int sum = 0;
    while (n--) {
      int x, cnt;
      cin >> x >> cnt;
      sum += cnt * x;
      while (cnt--) {
        memo |= memo << x;
      }
    }
    cout << ((~sum & 1) && memo.test(sum >> 1) ? "1\n" : "0\n");
  }

  return 0;
}