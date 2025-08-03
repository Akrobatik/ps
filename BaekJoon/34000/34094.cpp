// Title : 골드리치의 비밀 금고
// Link  : https://www.acmicpc.net/problem/34094 
// Time  : 272 ms
// Memory: 5928 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> arr(n);
  for (auto& e : arr) cin >> e;
  sort(arr.begin(), arr.end());

  if (arr.back() == 0) {
    cout << "0\n";
  } else {
    int x = 0;
    for (auto e : arr) {
      if (e == x) ++x;
    }
    cout << x + 1 << "\n";
  }
  for (auto e : arr) cout << e << " ";

  return 0;
}
