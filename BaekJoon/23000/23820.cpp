// Title : MEX
// Link  : https://www.acmicpc.net/problem/23820 
// Time  : 380 ms
// Memory: 11788 KB

#include <bits/stdc++.h>

using namespace std;

constexpr int kMax = 2e6 + 3;

bool check[kMax + 1];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> arr(n);
  for (auto& e : arr) cin >> e;
  sort(arr.begin(), arr.end());
  arr.erase(unique(arr.begin(), arr.end()), arr.end());

  for (int i = 0; i < arr.size(); i++) {
    int x = arr[i];
    for (int j = 0; j <= i; j++) {
      int y = arr[j];
      if (x * y > kMax) break;
      check[x * y] = true;
    }
  }

  int ans = 0;
  while (check[ans]) ++ans;
  cout << ans;

  return 0;
}
