// Title : 2025
// Link  : https://www.acmicpc.net/problem/35097 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<int> arr(101);
  for (int i = 1; i <= 100; i++) {
    arr[i] = arr[i - 1] + i;
  }

  vector<int> axr(101);
  for (int i = 1; i <= 100; i++) {
    axr[i] = arr[i] * arr[i];
  }

  int n;
  while (cin >> n && n) {
    cout << axr[n] << "\n";
  }

  return 0;
}