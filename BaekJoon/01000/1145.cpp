// Title : 적어도 대부분의 배수
// Link  : https://www.acmicpc.net/problem/1145 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  array<int, 5> arr;
  for (auto& e : arr) cin >> e;

  int ans = INT_MAX;
  for (int i = 0; i < 5; i++) {
    for (int j = i + 1; j < 5; j++) {
      int g = arr[i] * arr[j] / gcd(arr[i], arr[j]);
      for (int k = j + 1; k < 5; k++) {
        ans = min<int>(ans, g * arr[k] / gcd(g, arr[k]));
      }
    }
  }
  cout << ans;

  return 0;
}
