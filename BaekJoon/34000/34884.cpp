// Title : 당도 높은 수열
// Link  : https://www.acmicpc.net/problem/34884 
// Time  : 12 ms
// Memory: 3048 KB

#include <bits/stdc++.h>

using namespace std;

constexpr int kMax = 1 << 18;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<int> arr(kMax);
  iota(arr.begin(), arr.end(), 0);

  int n = kMax;
  for (int i = 1, j = 0; i < n; i++) {
    int b = n >> 1;
    while (j & b) j ^= b, b >>= 1;
    j |= b;
    if (i < j) swap(arr[i], arr[j]);
  }

  for (int i = 0; i < kMax; i++) {
    if (arr[i] < 150000) {
      cout << arr[i] + 1 << " ";
    }
  }

  return 0;
}