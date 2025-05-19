// Title : 특별상 눈치게임
// Link  : https://www.acmicpc.net/problem/33911 
// Time  : 8 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  int cnt[101] = {};
  while (n--) {
    int a, b, c;
    cin >> a >> b >> c;
    ++cnt[a], ++cnt[b], ++cnt[c];
  }

  int ans = 0;
  for (int i = 1; i <= 100; i++) {
    for (int j = 1; j < i; j++) {
      for (int k = 1; k < j; k++) {
        int maxx = 0;
        if (cnt[i] == 0) {
          maxx = i;
        } else if (cnt[j] == 0) {
          maxx = j;
        } else if (cnt[k] == 0) {
          maxx = k;
        }
        if (maxx == 0) continue;

        bool ok = true;
        for (int l = maxx + 1; l <= 100; l++) {
          if (l == i || l == j || l == k) continue;
          if (cnt[l] == 1) {
            ok = false;
            break;
          }
        }
        if (ok) ++ans;
      }
    }
  }
  cout << ans;

  return 0;
}