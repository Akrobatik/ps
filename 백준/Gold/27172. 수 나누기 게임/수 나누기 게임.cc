#include <bits/stdc++.h>

using namespace std;

int nums[100000];
int score[1000001];
bool memo[1000001];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> nums[i];

  vector<int> nums_copy(nums, nums + n);
  sort(nums_copy.begin(), nums_copy.end(), greater<int>());

  for (int i = 0; i < n; i++) {
    int v, vv;
    v = vv = nums_copy[i];
    memo[v] = true;
    while ((vv += v) <= 1000000) {
      if (memo[vv]) --score[vv], ++score[v];
    }
  }

  for (int i = 0; i < n; i++) cout << score[nums[i]] << " ";
  cout << "\n";

  return 0;
}
