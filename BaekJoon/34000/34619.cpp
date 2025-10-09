// Title : 소대 배정
// Link  : https://www.acmicpc.net/problem/34619 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int a, b, n, k;
  cin >> a >> b >> n >> k;

  int idx = 0;
  for (int i = 1; i <= a; i++) {
    for (int j = 1; j <= b; j++) {
      for (int l = 0; l < n; l++) {
        if (++idx == k) {
          cout << i << " " << j;
        }
      }
    }
  }

  return 0;
}