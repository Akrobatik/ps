// Title : 축생도
// Link  : https://www.acmicpc.net/problem/34045 
// Time  : 64 ms
// Memory: 5692 KB

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

  vector<int> cands;
  vector<bool> used(n + 1);
  for (int i = 1; i <= n; i++) {
    if (arr[i] == brr[i] || i == brr[i]) continue;
    int cur = arr[i], dst = brr[i];
    while (cur != dst) {
      if (arr[cur] == brr[cur] || cur != brr[cur] || used[cur]) {
        cout << "NO";
        return 0;
      }
      used[cur] = true;
      cur = arr[cur];
    }
  }
  cout << "YES";

  return 0;
}
