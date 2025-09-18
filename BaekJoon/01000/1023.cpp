// Title : 괄호 문자열
// Link  : https://www.acmicpc.net/problem/1023 
// Time  : 0 ms
// Memory: 2220 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int64_t n, k;
  cin >> n >> k;

  vector<vector<int64_t>> memo(n + 1, vector<int64_t>(n + 1, -1));

  auto Calc = [&](int aa, int bb) {
    int64_t all = 1LL << (n - aa);
    return all - [&](this auto&& self, int a, int b) -> int64_t {
      if (!(0 <= b && b <= min<int>(a, n - a))) return 0;
      if (a == n) return 1;

      auto& res = memo[a][b];
      if (res != -1) return res;
      return res = self(a + 1, b + 1) + self(a + 1, b - 1);
    }(aa, bb);
  };

  if (k >= Calc(0, 0)) {
    cout << "-1";
    return 0;
  }

  int cur = 0;
  string s(n, '(');
  for (int i = 0; k && i < n; i++) {
    if (cur >= 0) {
      int64_t val = Calc(i + 1, cur + 1);
      if (k >= val) k -= val, s[i] ^= 1;
      cur += (s[i] == '(' ? 1 : -1);
    } else {
      bitset<64> bits(k);
      for (int j = i; j < n; j++) s[j] ^= bits[n - j - 1];
      break;
    }
  }

  cout << s;

  return 0;
}