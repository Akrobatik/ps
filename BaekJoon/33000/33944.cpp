// Title : 3단 가시
// Link  : https://www.acmicpc.net/problem/33944 
// Time  : 388 ms
// Memory: 2168 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<int64_t> arr;
  vector<bool> brr, memo;

  int t;
  cin >> t;
  while (t--) {
    int64_t n;
    int x;
    cin >> n >> x;
    arr.resize(x);
    for (auto& e : arr) cin >> e;

    if (arr[0] > 6) {
      int64_t d = arr[0] - 6;
      for (int i = 0; i < x; i++) {
        arr[i] -= d;
      }
      n -= d;
    }

    for (int i = 1; i < x; i++) {
      if (arr[i] - arr[i - 1] <= 6) continue;

      int64_t d = arr[i] - (arr[i - 1] + 6);
      for (int j = i; j < x; j++) {
        arr[j] -= d;
      }
      n -= d;
    }

    if (n > arr.back() + 3) n = arr.back() + 3;

    brr.assign(n + 3, false);
    for (auto e : arr) brr[e] = true;

    memo.assign(n + 3, false);
    memo[0] = true;
    for (int i = 1; i <= n + 2; i++) {
      if (brr[i]) continue;
      memo[i] = (memo[i - 1] || (i - 4 >= 0 && memo[i - 4]));
    }
    cout << (memo[n + 2] ? "POSSIBLE\n" : "IMPOSSIBLE\n");
  }

  return 0;
}
