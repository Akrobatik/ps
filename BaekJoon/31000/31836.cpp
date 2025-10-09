// Title : 피보나치 기념품
// Link  : https://www.acmicpc.net/problem/31836 
// Time  : 0 ms
// Memory: 2156 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<int> arr, brr;

  int r = n % 3;
  if (r == 2) {
    arr.push_back(1), brr.push_back(2);
    for (int i = 1; i + 2 <= n; i++) {
      if (i % 3) {
        arr.push_back(i + 2);
      } else {
        brr.push_back(i + 2);
      }
    }
  } else {
    n = (n / 3) * 3;
    for (int i = 1; i <= n; i++) {
      if (i % 3) {
        arr.push_back(i);
      } else {
        brr.push_back(i);
      }
    }
  }

  cout << arr.size() << "\n";
  for (auto e : arr) cout << e << " ";
  cout << "\n";
  cout << brr.size() << "\n";
  for (auto e : brr) cout << e << " ";
  cout << "\n";

  return 0;
}