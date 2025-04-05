// Title : Parcel
// Link  : https://www.acmicpc.net/problem/16287
// Time  : 36 ms
// Memory: 5288 KB

#include <bits/stdc++.h>

using namespace std;

int memo[400001][2];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int w, n;
  cin >> w >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a.begin(), a.end());

  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      int sum = a[i] + a[j];
      if (memo[sum][0] == 0 || memo[sum][0] > j) memo[sum][0] = j;
      if (memo[sum][1] == 0 || memo[sum][1] < i) memo[sum][1] = i;
    }
  }

  bool found = false;
  for (int i = max<int>(3, w - 400000); i <= w / 2; i++) {
    if (memo[i][0] && memo[w - i][1] && memo[i][0] < memo[w - i][1]) {
      found = true;
      break;
    }
  }

  cout << (found ? "YES" : "NO") << endl;

  return 0;
}
