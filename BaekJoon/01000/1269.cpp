// Title : 대칭 차집합
// Link  : https://www.acmicpc.net/problem/1269 
// Time  : 76 ms
// Memory: 26436 KB

#include <bits/stdc++.h>

using namespace std;

constexpr int kMax = 1e8;

bitset<kMax + 1> s1, s2;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  int ans = n + m;
  while (n--) {
    int x;
    cin >> x;
    s1.set(x);
  }
  while (m--) {
    int x;
    cin >> x;
    s2.set(x); 
  }
  s1 &= s2;
  ans -= s1.count() * 2;
  cout << ans;

  return 0;
}
