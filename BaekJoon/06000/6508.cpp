// Title : A Game with Marbles
// Link  : https://www.acmicpc.net/problem/6508 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  while (cin >> n && n > 0) {
    int64_t sum = 0;
    vector<int64_t> arr(n + 1);
    for (int i = 1; i <= n; i++) {
      cin >> arr[i];
    }
    for (int i = n; i > 0; i--) {
      int64_t x = arr[i];
      for (int j = 1; j < i; j++) {
        arr[j] += x;
      }
      sum += x;
    }
    cout << sum << "\n";
  }

  return 0;
}