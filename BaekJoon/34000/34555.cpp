// Title : INU 순열
// Link  : https://www.acmicpc.net/problem/34555 
// Time  : 16 ms
// Memory: 2804 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<int> arr(n);
  int l = 1, r = n;
  for (int i = 0; i < n; i++) {
    arr[n - i - 1] = ((i & 1) ? r-- : l++);
  }

  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }

  return 0;
}