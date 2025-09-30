// Title : 합
// Link  : https://www.acmicpc.net/problem/1132 
// Time  : 32 ms
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

  int64_t maxx = 0;
  vector<int> vals(10);
  iota(vals.begin(), vals.end(), 0);
  do {
    if (mask[vals[0]]) continue;
    int64_t cur = 0;
    for (int i = 1; i < 10; i++) {
      cur += w[vals[i]] * i;
    }
    maxx = max<int64_t>(maxx, cur);
  } while (next_permutation(vals.begin(), vals.end()));
  cout << maxx;

  return 0;
}