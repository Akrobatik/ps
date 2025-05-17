// Title : 마지막 수강신청
// Link  : https://www.acmicpc.net/problem/33885 
// Time  : 0 ms
// Memory: 2024 KB

#include <bits/stdc++.h>

using namespace std;

using tup = tuple<int, bitset<120>>;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  auto Get = [](const string& s) {
    switch (s[1]) {
      case 'O':
        return 0;
        break;

      case 'U':
        return 1;
        break;

      case 'E':
        return 2;
        break;

      case 'H':
        return 3;
        break;

      case 'R':
        return 4;
        break;
    }
    assert(1);
  };

  int n, m;
  cin >> n >> m;
  vector<tup> arr(n);
  for (auto& [c, bits] : arr) {
    int k;
    cin >> c >> k;
    while (k--) {
      string s;
      int x;
      cin >> s >> x;
      bits.set(Get(s) * 24 + x);
    }
  }

  int limit = 1 << n;
  for (int i = 1; i < limit; i++) {
    vector<int> idx;
    uint32_t x = i;
    for (; x; x -= x & (-x)) idx.push_back(countr_zero(x));

    bitset<120> bits;
    int sum = 0;
    bool ok = true;
    for (auto ii : idx) {
      auto& [c, b] = arr[ii];
      sum += c;
      bitset<120> tmp = bits;
      tmp &= b;
      if (tmp.count()) {
        ok = false;
        break;
      }
      bits |= b;
    }

    if (ok && sum >= m) {
      cout << "YES";
      return 0;
    } 
  }
  cout << "NO";

  return 0;
}
