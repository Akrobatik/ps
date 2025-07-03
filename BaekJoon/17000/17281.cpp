// Title : ⚾
// Link  : https://www.acmicpc.net/problem/17281 
// Time  : 540 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<array<int, 9>> arr(n);
  for (auto& x : arr) {
    for (auto& e : x) cin >> e;
  }

  vector<int> _idx(9), idx(9);
  _idx[0] = 3;
  for (int i = 1; i < 9; i++) {
    _idx[i] = i - (i <= 3);
  }

  auto Calc = [&]() {
    for (int i = 0; i < 9; i++) {
      idx[_idx[i]] = i; 
    }

    int res = 0, i = 0;
    for (auto& x : arr) {
      int rem = 3, pos[4] = {};
      while (rem) {
        int t = x[idx[i++ % 9]];
        if (t == 0) {
          --rem;
        } else {
          pos[0] = 1;
          for (int j = 3; j >= 0; j--) {
            if (j + t <= 3) {
              pos[j + t] = pos[j];
            } else {
              res += pos[j];
            }
          }
          for (int j = 0; j < t; j++) {
            pos[j] = 0;
          }
        }
      }
    }
    return res;
  };

  int maxx = 0;
  int cnt = 0;
  do {
    ++cnt;
    maxx = max<int>(maxx, Calc());
  } while (next_permutation(_idx.begin() + 1, _idx.end()));
  cout << maxx;

  return 0;
}
