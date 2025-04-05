// Title : 좌표 압축
// Link  : https://www.acmicpc.net/problem/18870
// Time  : 440 ms
// Memory: 9840 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> xs(n);
  for (int i = 0; i < n; i++) cin >> xs[i];
  vector<int> sorted(xs);
  sort(sorted.begin(), sorted.end());
  sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());
  for (auto x : xs) {
    auto it = lower_bound(sorted.begin(), sorted.end(), x);
    cout << it - sorted.begin() << " ";
  }

  return 0;
}
