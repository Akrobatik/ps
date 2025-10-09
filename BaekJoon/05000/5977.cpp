// Title : Mowing the Lawn
// Link  : https://www.acmicpc.net/problem/5977 
// Time  : 12 ms
// Memory: 3592 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;

  vector<int64_t> fwd(n + 1);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    fwd[i + 1] = fwd[i] + x;
  }

  deque<int> dq;
  vector<int64_t> memo(n + 1);

  auto Calc = [&](int i) {
    return memo[i - 1] - fwd[i];
  };

  for (int i = 1; i <= n; i++) {
    while (!dq.empty() && dq.front() + k < i) dq.pop_front();

    int64_t cur = Calc(i);
    while (!dq.empty() && Calc(dq.back()) <= cur) dq.pop_back();
    dq.push_back(i);

    memo[i] = fwd[i] + (i <= k ? 0 : Calc(dq.front()));
  }
  cout << memo[n] << '\n';

  return 0;
}