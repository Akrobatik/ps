// Title : 천상도
// Link  : https://www.acmicpc.net/problem/34042 
// Time  : 88 ms
// Memory: 2024 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<int> arr, brr;

  int n, m;
  cin >> n >> m;
  while (m--) {
    arr.clear(), brr.clear();
    int zero = 0, x;
    for (int i = 0; i < n; i++) {
      cin >> x;
      if (x == 0) {
        ++zero;
      } else if (x < 0) {
        arr.push_back(-x);
      } else {
        brr.push_back(x);
      }
    }
    sort(arr.begin(), arr.end(), greater<int>());
    sort(brr.begin(), brr.end(), greater<int>());

    int64_t maxx = 1;
    int cnt = 0;
    for (int i = 2; i <= arr.size(); i += 2) {
      maxx *= arr[i - 2];
      maxx *= arr[i - 1];
      cnt += 2;
    }
    for (int i = 0; i < brr.size(); i++) {
      maxx *= brr[i];
      ++cnt;
    }

    if (n == 1) {
      cout << x << "\n";
    } else {
      cout << (cnt ? maxx : 0) << "\n";
    }
  }

  return 0;
}