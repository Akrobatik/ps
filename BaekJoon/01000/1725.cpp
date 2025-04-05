// Title : 히스토그램
// Link  : https://www.acmicpc.net/problem/1725
// Time  : 8 ms
// Memory: 5220 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  while ((cin >> n) && n) {
    int64_t maxx = 0;
    vector<pair<int64_t, int>> vec;
    for (int i = 0; i < n; i++) {
      int64_t now;
      cin >> now;
      while (!vec.empty() && vec.back().first > now) {
        auto [h, idx] = vec.back();
        vec.pop_back();

        int64_t sum;
        if (vec.empty()) {
          sum = h * i;
        } else {
          sum = h * (i - vec.back().second - 1);
        }
        if (maxx < sum) maxx = sum;
      }
      vec.push_back({now, i});
    }

    while (!vec.empty()) {
      auto [h, idx] = vec.back();
      vec.pop_back();

      int64_t sum;
      if (vec.empty()) {
        sum = h * n;
      } else {
        sum = h * (n - vec.back().second - 1);
      }
      if (maxx < sum) maxx = sum;
    }

    cout << maxx << "\n";
  }

  return 0;
}
