// Title : Difference Maximization
// Link  : https://www.acmicpc.net/problem/33802 
// Time  : 16 ms
// Memory: 2416 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int64_t n, m;
  cin >> n >> m;
  vector<int> arr;
  arr.reserve(n);
  int64_t z = 0;
  int64_t a1 = 0, a2 = 0;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    if (x == 0) {
      ++z;
    } else {
      arr.push_back(x);
      a1 += x - 1;
      a2 += m - x;
    }
  }

  sort(arr.begin(), arr.end());
  int64_t c = 0, sum = 0;
  for (int i = 0; i < arr.size(); i++) {
    c += (int64_t)arr[i] * i - sum;
    sum += arr[i];
  }

  auto Calc = [&](int64_t x) {
    int64_t y = z - x;
    return (m - 1) * x * y + a1 * x + a2 * y + c;
  };

  int l = 0, r = z + 1;
  while (l + 2 < r) {
    int ll = (l + l + r) / 3;
    int rr = (l + r + r) / 3;
    if (Calc(ll) < Calc(rr)) {
      l = ll;
    } else {
      r = rr;
    }
  }

  int64_t maxx = 0;
  for (int i = l; i < r; i++) {
    maxx = max<int64_t>(maxx, Calc(i));
  }
  cout << maxx;

  return 0;
}
