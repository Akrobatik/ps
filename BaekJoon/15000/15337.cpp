// Title : Starting a Scenic Railroad Service
// Link  : https://www.acmicpc.net/problem/15337 
// Time  : 36 ms
// Memory: 4756 KB

#include <bits/stdc++.h>

using namespace std;

constexpr int kMax = 1e5;

int memo[kMax + 1];
int fwd[kMax + 1], bwd[kMax + 1];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<pair<int, int>> arr(n);
  for (auto& [l, r] : arr) {
    cin >> l >> r;
    ++memo[l], --memo[r];
    ++fwd[r], ++bwd[l];
  }

  int a1 = 0;
  for (int i = 1; i <= kMax; i++) {
    fwd[i] += fwd[i - 1];
    bwd[kMax - i] += bwd[kMax - i + 1];
  }
  for (auto [l, r] : arr) {
    a1 = max<int>(a1, n - fwd[l] - bwd[r]);
  }

  int a2 = 0;
  for (int i = 1; i <= kMax; i++) {
    memo[i] += memo[i - 1];
    a2 = max<int>(a2, memo[i]);
  }

  cout << a1 << " " << a2;

  return 0;
}
