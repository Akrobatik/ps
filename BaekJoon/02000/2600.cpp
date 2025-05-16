// Title : 구슬게임
// Link  : https://www.acmicpc.net/problem/2600 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int arr[3];
  for (auto& e : arr) cin >> e;
  sort(arr, arr + 3);

  int memo[501] = {};
  for (int i = 1; i <= 500; i++) {
    int nxt[501] = {};
    for (auto e : arr) {
      if (e > i) break;
      nxt[memo[i - e]] = true;
    }

    for (int j = 0; j <= 500; j++) {
      if (nxt[j]) continue;
      memo[i] = j;
      break;
    }
  }

  int t = 5;
  while (t--) {
    int b1, b2;
    cin >> b1 >> b2;
    cout << ((memo[b1] ^ memo[b2]) ? "A\n" : "B\n");
  }

  return 0;
}
