// Title : unique(str)=KCPC
// Link  : https://www.acmicpc.net/problem/35159 
// Time  : 48 ms
// Memory: 10984 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  cin >> s;

  int n = s.size();
  int nk = 0, nc = 0, np = 0;
  for (auto c : s) {
    if (c == 'K') {
      ++nk;
    } else if (c == 'C') {
      ++nc;
    } else {
      ++np;
    }
  }

  vector<int> arr(n), fwt;

  auto Inc = [&](int i) {
    for (; i <= n; i += i & (-i)) ++fwt[i];
  };

  auto Sum = [&](int i) {
    int64_t res = 0;
    for (; i > 0; i -= i & (-i)) res += fwt[i];
    return res;
  };

  auto Calc = [&](int x) {
    int idx[4] = {0, nk, nk + x, nk + x + np};

    int cnt = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == 'K') {
        arr[i] = ++idx[0];
      } else if (s[i] == 'P') {
        arr[i] = ++idx[2];
      } else if (cnt++ < x) {
        arr[i] = ++idx[1];
      } else {
        arr[i] = ++idx[3];
      }
    }

    int64_t res = 0;
    fwt.assign(n + 1, 0);
    for (int i = 0; i < n; i++) {
      res += i - Sum(arr[i]);
      Inc(arr[i]);
    }
    return res;
  };

  int64_t cur = Calc(1);

  int idx = 0;
  int nnk = 0, nnc = 0, nnp = 0;
  while (s[idx] != 'C') ++idx;

  for (int i = 0; i <= idx; i++) {
    if (s[i] == 'K') {
      ++nnk;
    } else if (s[i] == 'C') {
      ++nnc;
    } else {
      ++nnp;
    }
  }

  for (int i = idx + 1; i < n; i++) {
    if (s[i] == 'K') {
      ++nnk;
    } else if (s[i] == 'P') {
      ++nnp;
    } else {
      if (++nnc == nc) break;

      int64_t dt = (np - nnp) - nnp;
      if (dt <= 0) break;
      cur -= dt;
    }
  }
  cout << cur;

  return 0;
}