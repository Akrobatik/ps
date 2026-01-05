// Title : 최대공약수 완충재
// Link  : https://www.acmicpc.net/problem/34967 
// Time  : 4 ms
// Memory: 2432 KB

#include <bits/stdc++.h>

using namespace std;

int64_t GCD(int64_t a, int64_t b) {
  while (b) a %= b, swap(a, b);
  return a;
}

int64_t LCM(int64_t a, int64_t b) {
  return (a / GCD(a, b)) * b;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<int> axr;
  for (int i = 0; i < n; i++) {
    int x = (i + 1) >> 1;
    if (i & 1) {
      axr.push_back(10000 - x);
    } else {
      axr.push_back(10000 + x);
    }
  }

  vector<int64_t> arr(n);
  for (int i = 0; i < n; i++) {
    if (i == 0) {
      arr[i] = axr[0];
    } else if (i + 1 == n) {
      arr[i] = axr[i - 1];
    } else {
      arr[i] = LCM(axr[i - 1], axr[i]);
    }
  }

  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }

  return 0;
}