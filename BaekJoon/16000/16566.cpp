// Title : 카드 게임
// Link  : https://www.acmicpc.net/problem/16566
// Time  : 728 ms
// Memory: 33276 KB

#include <bits/stdc++.h>

using namespace std;

int nums[4000000];
int memo[4000002];

int Find(int id) {
  if (memo[id] == id) return id;
  return memo[id] = Find(memo[id]);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 0; i < m; i++) cin >> nums[i];
  sort(nums, nums + m);

  auto ne = nums;
  for (int i = 1; i <= n; i++) {
    if (ne == nums + m) break;
    memo[i] = *ne;
    if (i == *ne) ++ne;
  }

  while (k--) {
    int v;
    cin >> v;
    int vv = Find(v + 1);
    if (vv) {
      cout << vv << "\n";
      memo[vv] = memo[v + 1] = memo[vv + 1];
    } else {
      int vvv = Find(1);
      cout << vvv << endl;
      memo[vvv] = memo[1] = memo[vvv + 1];
    }
  }

  return 0;
}
