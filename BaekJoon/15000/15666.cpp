// Title : N과 M （12）
// Link  : https://www.acmicpc.net/problem/15666
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int n, m;
int nums[8];
int ans[8];

void PrintUnit(int depth, int cur) {
  ans[depth] = cur;
  if (depth + 1 == m) {
    for (int i = 0; i < m; i++) cout << nums[ans[i]] << " ";
    cout << "\n";
    return;
  }

  for (int i = cur; i < n; i++) {
    PrintUnit(depth + 1, i);
  }
}

void Print() {
  for (int i = 0; i < n; i++) {
    PrintUnit(0, i);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> nums[i];
  sort(nums, nums + n);
  n = distance(nums, unique(nums, nums + n));

  Print();

  return 0;
}
