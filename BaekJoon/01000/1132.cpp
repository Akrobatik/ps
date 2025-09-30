// Title : 합
// Link  : https://www.acmicpc.net/problem/1132 
// Time  : 0 ms
// Memory: 2024 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int64_t pw[12] = {1};
  for (int i = 1; i < 12; i++) {
    pw[i] = pw[i - 1] * 10;
  }

  int64_t w[10] = {};
  bool mask[10] = {};

  int n;
  cin >> n;
  while (n--) {
    string s;
    cin >> s;
    int ns = s.size();
    mask[s[0] - 'A'] = true;
    for (int i = 0; i < ns; i++) {
      int x = s[ns - i - 1] - 'A';
      w[x] += pw[i];
    }
  }

  vector<int> vals(9);

  int64_t maxx = 0;
  for (int i = 0; i < 10; i++) {
    if (mask[i]) continue;

    iota(vals.begin(), vals.end(), 0);
    for (int j = i; j < 9; j++) ++vals[j];

    sort(vals.begin(), vals.end(), [&](int lhs, int rhs) {
      return w[lhs] < w[rhs];
    });

    int64_t cur = 0;
    for (int j = 0; j < 9; j++) {
      cur += w[vals[j]] * (j + 1);
    }
    maxx = max<int64_t>(maxx, cur);
  }
  cout << maxx;

  return 0;
}