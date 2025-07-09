// Title : 스타트와 링크
// Link  : https://www.acmicpc.net/problem/14889 
// Time  : 44 ms
// Memory: 2024 KB

#include <bits/stdc++.h>

using namespace std;

int mat[20][20];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> mat[i][j];
    }
  }

  int minn = INT_MAX;
  vector<int> arr, brr;
  int limit = 1 << n, half = n >> 1;
  for (int i = 0; i < limit; i++) {
    bitset<20> bits(i);
    if (bits.count() != half) continue;
    arr.clear(), brr.clear();
    for (int j = 0; j < n; j++) {
      if (bits.test(j)) {
        arr.push_back(j);
      } else {
        brr.push_back(j);
      }
    }

    int av = 0, bv = 0;
    for (auto e : arr) {
      for (int j = 0; j < half; j++) {
        av += mat[e][arr[j]];
      }
    }
    for (auto e : brr) {
      for (int j = 0; j < half; j++) {
        bv += mat[e][brr[j]];
      }
    }
    minn = min<int>(minn, abs(av - bv));
  }
  cout << minn;

  return 0;
}
