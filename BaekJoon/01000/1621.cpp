// Title : 조삼모사
// Link  : https://www.acmicpc.net/problem/1621 
// Time  : 148 ms
// Memory: 16232 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k, c;
  cin >> n >> k >> c;

  vector<int64_t> memo(n + 1, INT64_MAX);
  vector<bool> jmp(n + 1);
  memo[0] = 0;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    if (memo[i + 1] >= memo[i] + x) {
      memo[i + 1] = memo[i] + x;
      jmp[i + 1] = false;
    }
    if (i + k <= n && memo[i + k] > memo[i] + c) {
      memo[i + k] = memo[i] + c;
      jmp[i + k] = true;
    }
  }

  vector<int> axr;
  int idx = n;
  while (idx >= k) {
    if (jmp[idx]) {
      axr.push_back(idx - k + 1);
      idx -= k;
    } else {
      --idx;
    }
  }

  cout << memo[n] << "\n"
       << axr.size() << "\n";
  for (auto e : views::reverse(axr)) cout << e << " ";

  return 0;
}