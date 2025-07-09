// Title : 01타일
// Link  : https://www.acmicpc.net/problem/1904 
// Time  : 4 ms
// Memory: 5928 KB

#include <bits/stdc++.h>

using namespace std;

constexpr int kMod = 15746;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> arr(n + 1);
  arr[0] = arr[1] = 1;
  for (int i = 2; i <= n; i++) {
    arr[i] = arr[i - 2] + arr[i - 1];
    if (arr[i] >= kMod) arr[i] -= kMod;
  }
  cout << arr[n];

  return 0;
}
