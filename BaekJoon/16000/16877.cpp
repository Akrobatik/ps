// Title : 핌버
// Link  : https://www.acmicpc.net/problem/16877 
// Time  : 100 ms
// Memory: 13740 KB

#include <bits/stdc++.h>

using namespace std;

constexpr int kMax = 3e6;

int memo[kMax + 1];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<int> arr{1, 2};
  int idx = 0;
  while (arr[idx] + arr[idx + 1] <= kMax) arr.push_back(arr[idx] + arr[idx + 1]), ++idx;

  for (int i = 0; i <= kMax; i++) {
    bool nxt[32] = {};
    for (auto e : arr) {
      if (e > i) break;
      nxt[memo[i - e]] = true;
    }
    for (int j = 0; j < 32; j++) {
      if (nxt[j]) continue;
      memo[i] = j;
      break;
    }
  }

  int n, ans = 0;
  cin >> n;
  while (n--) {
    int x;
    cin >> x;
    ans ^= memo[x];
  }
  cout << (ans ? "koosaga" : "cubelover");

  return 0;
}
