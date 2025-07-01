// Title : 암기왕
// Link  : https://www.acmicpc.net/problem/2776 
// Time  : 556 ms
// Memory: 5932 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<int> arr;

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    arr.resize(n);
    for (auto& e : arr) cin >> e;
    sort(arr.begin(), arr.end());

    int m;
    cin >> m;
    while (m--) {
      int x;
      cin >> x;
      cout << binary_search(arr.begin(), arr.end(), x) << "\n";
    }
  }

  return 0;
}
