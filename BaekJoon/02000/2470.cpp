// Title : 두 용액
// Link  : https://www.acmicpc.net/problem/2470 
// Time  : 12 ms
// Memory: 2412 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;
  vector<int> arr(n);
  for (auto& e : arr) cin >> e;
  sort(arr.begin(), arr.end());

  int minn = INT_MAX, ml, mr;
  int l = 0, r = n - 1;
  while (l < r) {
    int sum = arr[l] + arr[r];
    if (minn > abs(sum)) minn = abs(sum), ml = l, mr = r;
    if (sum < 0) {
      ++l;
    } else {
      --r;
    }
  }
  cout << arr[ml] << " " << arr[mr];

  return 0;
}
