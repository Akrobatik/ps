// Title : 축생도
// Link  : https://www.acmicpc.net/problem/34045 
// Time  : 64 ms
// Memory: 5536 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> arr(n + 1), brr(n + 1), cnt(n + 1);
  for (int i = 1; i <= n; i++) cin >> arr[i], ++cnt[arr[i]];
  for (int i = 1; i <= n; i++) cin >> brr[i], --cnt[brr[i]];

  for (int i = 1; i <= n; i++) {
    if (cnt[i]) {
      cout << "NO";
      return 0;
    }
  }

  int c1 = 0, c2 = 0;
  for (int i = 1; i <= n; i++) {
    if (arr[i] == brr[i]) {
      ++c1;
    } else if (i == brr[i]) {
      ++c2;
    }
  }
  cout << ((c1 + c2 * 2) >= n ? "YES" : "NO");

  return 0;
}