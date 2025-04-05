// Title : ATM
// Link  : https://www.acmicpc.net/problem/11399
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> vec(n), psum(n);
  while (n--) cin >> vec[n];
  sort(vec.begin(), vec.end());
  partial_sum(vec.begin(), vec.end(), psum.begin());
  cout << accumulate(psum.begin(), psum.end(), 0);

  return 0;
}
