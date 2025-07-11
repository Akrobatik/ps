// Title : Last Factorial Digit
// Link  : https://www.acmicpc.net/problem/31048 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int arr[6] = {1, 1, 2, 6, 4, 0};

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    cout << arr[min<int>(n, 5)] << "\n";
  }

  return 0;
}