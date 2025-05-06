// Title : 숫자 카드
// Link  : https://www.acmicpc.net/problem/10815 
// Time  : 140 ms
// Memory: 4460 KB

#include <bits/stdc++.h>

using namespace std;

constexpr int kMax = 1e7;

bitset<kMax * 2 + 1> memo;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  while (n--) {
    int x;
    cin >> x;
    memo.set(x + kMax);
  }

  int m;
  cin >> m;
  while (m--) {
    int x;
    cin >> x;
    cout << memo.test(x + kMax) << " ";
  }

  return 0;
}
