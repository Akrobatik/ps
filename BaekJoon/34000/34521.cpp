// Title : !제곱수 순열
// Link  : https://www.acmicpc.net/problem/34521 
// Time  : 80 ms
// Memory: 6176 KB

#include <bits/stdc++.h>

using namespace std;

constexpr int kMax = 2e6;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<bool> sqr(kMax);
  for (int i = 1; i * i < kMax; i++) {
    sqr[i * i] = true;
  }

  vector<int> arr;

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    arr.resize(n);
    iota(arr.begin(), arr.end(), 1);
    for (int i = 2; i < n; i++) {
      int x = arr[i - 1] + arr[i];
      if (sqr[x]) swap(arr[i - 2], arr[i - 1]);
    }
    for (auto e : arr) cout << e << " ";
    cout << "\n";
  }

  return 0;
}