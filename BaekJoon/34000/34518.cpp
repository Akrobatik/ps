// Title : Double Permutation
// Link  : https://www.acmicpc.net/problem/34518 
// Time  : 0 ms
// Memory: 2160 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  if (n % 4 == 2 || n % 4 == 3) {
    cout << "-1";
    return 0;
  }

  vector<vector<int>> arr(2, vector<int>(n));
  int l = 0, r = n - 1;
  for (int i = n; i >= 4; i -= 4, l += 2, r -= 2) {
    arr[0][l] = arr[1][r] = i;
    arr[0][r] = arr[1][l + 1] = i - 1;
    arr[1][l] = arr[1][r - 1] = i - 2;
    arr[0][l + 1] = arr[0][r - 1] = i - 3;
  }

  if (n % 4 == 1) {
    arr[0][l] = arr[1][l] = 1;
  }

  for (auto e : arr[0]) cout << e << " ";
  cout << "\n";
  for (auto e : arr[1]) cout << e << " ";

  return 0;
}