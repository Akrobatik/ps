// Title : 배낭 문제 준비하기
// Link  : https://www.acmicpc.net/problem/11914 
// Time  : 0 ms
// Memory: 2816 KB

#include <bits/stdc++.h>

using namespace std;

constexpr int kMax = 300;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int64_t t;
  cin >> t;

  if (t <= 3) {
    cout << t << " 1\n";
    for (int i = 0; i < t; i++) cout << "1 ";
    return 0;
  }

  vector<int> arr;
  vector<vector<int64_t>> memo(kMax + 1, vector<int64_t>(kMax + 1));
  memo[0][0] = 1;

  auto Push = [&](int x) {
    int n = arr.size();
    for (int i = 0; i <= kMax; i++) {
      memo[n + 1][i] = memo[n][i] + (i >= x ? memo[n][i - x] : 0);
    }
    arr.push_back(x);
  };

  vector<int> axr{1, 1};
  while (axr.back() <= kMax) {
    int n = axr.size();
    axr.push_back(axr[n - 1] + axr[n - 2]);
  }

  for (int i = 1; i + 1 < axr.size(); i++) {
    Push(axr[i]);
  }

  while (memo[arr.size()][kMax] != t) {
    int n = arr.size();
    for (int i = 1; i <= kMax; i++) {
      if (memo[n][kMax] + memo[n][kMax - i] <= t) {
        Push(i);
        break;
      }
    }
  }

  cout << arr.size() << " " << kMax << "\n";
  for (auto e : arr) cout << e << " ";

  return 0;
}