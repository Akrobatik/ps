// Title : 크게 만들기
// Link  : https://www.acmicpc.net/problem/2812 
// Time  : 4 ms
// Memory: 3148 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  string s;
  cin >> n >> k >> s;

  string dst;
  dst.reserve(n);
  for (auto c : s) {
    while (k && !dst.empty() && dst.back() < c) --k, dst.pop_back();
    dst.push_back(c);
  }
  while (k--) dst.pop_back();
  cout << dst;

  return 0;
}
