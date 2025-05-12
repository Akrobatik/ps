// Title : 정말 간단한 문제
// Link  : https://www.acmicpc.net/problem/33849 
// Time  : 136 ms
// Memory: 5932 KB

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
  vector<int> xrr(n), yrr(n);
  for (auto& e : xrr) cin >> e;
  for (auto& e : yrr) cin >> e;

  int l = 0, maxx = 1, cnt = 1;
  for (int i = 1; i < n; i++) {
    int64_t old = (int64_t)xrr[i] * yrr[l];
    int64_t cur = (int64_t)xrr[l] * yrr[i];
    if (old == cur) {
      maxx = max<int>(maxx, ++cnt);
    } else if (old < cur) {
      l = i, maxx = 1, cnt = 1;
    } else {
      cnt = 0;
    }
  }

  int64_t g = GCD(xrr[l], yrr[l]);
  cout << yrr[l] / g << " " << xrr[l] / g << "\n"
       << maxx;

  return 0;
}
