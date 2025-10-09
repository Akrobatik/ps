// Title : 특이한 수열
// Link  : https://www.acmicpc.net/problem/13018 
// Time  : 8 ms
// Memory: 2412 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;

  if (n == k) {
    cout << "Impossible";
    return 0;
  }

  vector<int> arr(n);
  iota(arr.begin(), arr.end(), 1);

  int r = n - k;
  if (r & 1) {
    for (int i = 1; i < r; i += 2) {
      swap(arr[i], arr[i + 1]);
    }
  } else {
    for (int i = 0; i < r; i += 2) {
      swap(arr[i], arr[i + 1]);
    }
  }

  for (auto e : arr) cout << e << " ";

  return 0;
}