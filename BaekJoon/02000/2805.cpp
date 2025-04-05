// Title : 나무 자르기
// Link  : https://www.acmicpc.net/problem/2805
// Time  : 156 ms
// Memory: 5932 KB

#include <bits/stdc++.h>

using namespace std;

vector<uint32_t> trees;

uint64_t GetSum(uint32_t h) {
  uint64_t sum = 0;
  for (auto t : trees) {
    if (t > h) {
      sum += t - h;
    } else {
      break;
    }
  }
  return sum;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  uint32_t n;
  uint64_t m;
  cin >> n >> m;
  trees.resize(n);
  for (uint32_t i = 0; i < n; i++) {
    cin >> trees[i];
  }
  sort(trees.begin(), trees.end(), greater<uint32_t>());

  uint32_t max = 0;
  uint32_t start = 0;
  uint32_t end = trees.front();
  while (start <= end) {
    uint32_t mid = (start + end) / 2;
    uint64_t sum = GetSum(mid);
    if (sum >= m) {
      start = mid + 1;
      if (mid > max) max = mid;
    } else {
      end = mid - 1;
    }
  }

  cout << max << endl;

  return 0;
}
