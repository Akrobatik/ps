// Title : 1차원
// Link  : https://www.acmicpc.net/problem/25686 
// Time  : 8 ms
// Memory: 2532 KB

#include <bits/stdc++.h>

using namespace std;

constexpr int kMax = 1 << 17;

int arr[kMax];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  iota(arr, arr + kMax, 1);
  for (int i = 1, j = 0; i < kMax; i++) {
    int b = kMax >> 1;
    while (j & b) j ^= b, b >>= 1;
    j |= b;
    if (i < j) swap(arr[i], arr[j]);
  }

  for (int i = 0; i < kMax; i++) {
    if (arr[i] <= n) cout << arr[i] << " ";
  }

  return 0;
}
