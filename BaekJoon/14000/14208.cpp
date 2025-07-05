// Title : 수열 찾기
// Link  : https://www.acmicpc.net/problem/14208 
// Time  : 0 ms
// Memory: 2024 KB

#include <bits/stdc++.h>

using namespace std;

int64_t GCD(int64_t a, int64_t b) {
  while (b) a %= b, swap(a, b);
  return a;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> brr(n);
  for (auto& e : brr) cin >> e, ++e;
  sort(brr.begin(), brr.end());

  int64_t l = 1;
  for (auto e : brr) l *= (e / GCD(l, e));

  int64_t s = 0;
  for (auto e : brr) s += l / e;

  bool dup = false;
  for (int i = 1; !dup && i < n; i++) {
    dup = (brr[i - 1] == brr[i]);
  }
  cout << (s < l || (!dup && s == l));

  return 0;
}
