// Title : SCSC 문자열 놀이
// Link  : https://www.acmicpc.net/problem/33974 
// Time  : 4 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

constexpr int table[5][2] = {
    {1, 0}, {1, 2}, {3, 0}, {1, 4}, {4, 4}};

bool Check(const string& str) {
  int st = 0;
  for (auto c : str) {
    int x = (c == 'C' ? 1 : 0);
    st = table[st][x];
  }
  return st == 4;
}

int64_t Count(int l) {
  int64_t memo[46][5] = {};
  memo[0][0] = 1;
  for (int i = 0; i < l; i++) {
    for (int j = 0; j < 5; j++) {
      if (memo[i][j] == 0) continue;
      memo[i + 1][table[j][0]] += memo[i][j];
      memo[i + 1][table[j][1]] += memo[i][j];
    }
  }
  return memo[l][4];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int64_t n, s, c;
    cin >> n >> s >> c;

    int64_t ans = 0;

    if (s == c) {
      if (n % s == 0) {
        bitset<45> bits(n / s + 1);
        if (bits.count() == 1) {
          int l = 0;
          while (!bits.test(l)) ++l;
          ans = Count(l);
        }
      }
    } else {
      __int128 d = s - c;
      for (int i = 4; i <= 45; i++) {
        __int128 p = 1LL << i;
        __int128 x = c * (p - 1);
        __int128 y = n - x;
        if (y % d == 0) {
          __int128 z = y / d;
          if (0 <= z && z < p) {
            bitset<45> bits(z);
            string str(i, 'C');
            for (int j = 0; j < i; j++) {
              if (bits.test(j)) str[i - j - 1] = 'S';
            }
            ans += Check(str);
          }
        }
      }
    }
    cout << ans << "\n";
  }

  return 0;
}
