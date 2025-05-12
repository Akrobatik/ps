// Title : Cute Matrix
// Link  : https://www.acmicpc.net/problem/33804 
// Time  : 4 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  if (!has_single_bit((uint32_t)n)) {
    cout << "0";
    return 0;
  }

  vector<int> arr(n);
  iota(arr.begin(), arr.end(), 1);
  for (int i = 1, j = 0; i < n; i++) {
    int b = n >> 1;
    while (j & b) j ^= b, b >>= 1;
    j |= b;
    if (i < j) swap(arr[i], arr[j]);
  }
  cout << "1\n";
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << arr[i ^ j] << " ";
    }
    cout << "\n";
  }

  return 0;
}
