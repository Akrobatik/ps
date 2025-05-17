// Title : 카드 뭉치
// Link  : https://www.acmicpc.net/problem/33886 
// Time  : 8 ms
// Memory: 2152 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> arr(n + 1);
  for (int i = 1; i <= n; i++) cin >> arr[i];

  vector<int> memo(n + 1, INT_MAX >> 1);
  memo[0] = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < i; j++) {
      int k = j + 1;
      if (arr[k] >= i - j) {
        memo[i] = min<int>(memo[i], memo[j] + 1);
      }
    }
  }
  cout << memo[n];

  return 0;
}
