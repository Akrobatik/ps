// Title : 축생도
// Link  : https://www.acmicpc.net/problem/34045 
// Time  : 68 ms
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
    int nxt = arr[i];
    if (arr[nxt] == brr[nxt] || nxt != brr[nxt] || used[nxt]) {
      cout << "NO";
      return 0;
    }
    used[nxt] = true;
  }
  cout << "YES";

  return 0;
}