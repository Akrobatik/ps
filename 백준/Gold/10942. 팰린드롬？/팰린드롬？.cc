#include <bits/stdc++.h>

using namespace std;

int nums[2001];
bool memo[2001][2001];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> nums[i];

  for (int i = 1; i <= n; i++) {
    for (int b = 1; b <= n - i + 1; b++) {
      int e = b + i - 1;
      if (i == 1) {
        memo[b][e] = true;
      } else if (i == 2) {
        if (nums[b] == nums[e]) memo[b][e] = true;
      } else {
        if (nums[b] == nums[e] && memo[b + 1][e - 1]) memo[b][e] = true;
      }
    }
  }

  int m;
  cin >> m;
  while (m--) {
    int b, e;
    cin >> b >> e;
    cout << (memo[b][e] ? 1 : 0) << "\n";
  }

  return 0;
}
