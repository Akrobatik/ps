// Title : 동전 뒤집기
// Link  : https://www.acmicpc.net/problem/1285 
// Time  : 48 ms
// Memory: 18416 KB

#include <bits/stdc++.h>

using namespace std;

void FWHT(vector<int64_t>& arr) {
  int n = arr.size();
  for (int len = 1; len < n; len <<= 1) {
    for (int i = 0; i < n; i += (len << 1)) {
      for (int j = 0; j < len; j++) {
        int64_t u = arr[i + j];
        int64_t v = arr[i + j + len];
        arr[i + j] = u + v;
        arr[i + j + len] = u - v;
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<string> board(n);
  for (auto& s : board) cin >> s;

  int sz = 1 << n;
  vector<int64_t> arr(sz), brr(sz);
  for (int j = 0; j < n; j++) {
    int x = 0;
    for (int i = 0; i < n; i++) {
      if (board[i][j] == 'T') x |= (1 << i);
    }
    ++arr[x];
  }
  for (int i = 0; i < sz; i++) {
    bitset<32> bits(i);
    brr[i] = min<int>(bits.count(), n - bits.count());
  }

  FWHT(arr);
  FWHT(brr);
  for (int i = 0; i < sz; i++) {
    arr[i] *= brr[i];
  }
  FWHT(arr);

  int64_t minn = INT64_MAX;
  for (int i = 0; i < sz; i++) {
    minn = min<int64_t>(minn, arr[i] >> n);
  }
  cout << minn;

  return 0;
}
