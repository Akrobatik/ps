// Title : 릴레이 가위바위보 게임
// Link  : https://www.acmicpc.net/problem/35106 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  int cnt[4] = {};
  for (int i = 1; i <= n * 3; i++) {
    int x;
    cin >> x;
    ++cnt[x];
  }

  for (int i = 1; i <= 3; i++) {
    if (cnt[i] == n - 1) cout << i << "\n";
  }
  for (int i = 1; i <= 3; i++) {
    if (cnt[i] == n + 1) cout << i << "\n";
  }

  return 0;
}