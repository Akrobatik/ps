// Title : gcd와 set
// Link  : https://www.acmicpc.net/problem/33837 
// Time  : 128 ms
// Memory: 5932 KB

#include <bits/stdc++.h>

using namespace std;

constexpr int kMax = 5000;

int GCD(int a, int b) {
  while (b) a %= b, swap(a, b);
  return a;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int cnt[kMax + 1] = {}, sum[kMax + 1] = {};

  int n;
  cin >> n;
  if (n == 1) {
    cin >> n;
    cout << n;
    return 0;
  }

  vector<int> arr(n);
  for (auto& e : arr) cin >> e, ++cnt[e];
  sort(arr.begin(), arr.end());
  arr.erase(unique(arr.begin(), arr.end()), arr.end());

  for (int i = 1; i <= kMax; i++) {
    for (int j = i; j <= kMax; j += i) {
      sum[i] += cnt[j];
    }
  }

  int maxx = 0;
  for (int i = 1; i <= kMax; i++) {
    if (sum[i] == 0) continue;
    if (sum[i] == n) {
      maxx = max<int>(maxx, i << 1);
    } else {
      int g = 0;
      for (auto e : arr) {
        if (e % i == 0) continue;
        g = GCD(g, e);
        if (g == 1) break;
      }
      maxx = max<int>(maxx , i + g);
    }
  }
  cout << maxx;

  return 0;
}
