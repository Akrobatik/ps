// Title : 문자열 집합
// Link  : https://www.acmicpc.net/problem/14425 
// Time  : 76 ms
// Memory: 2228 KB

#include <bits/stdc++.h>

using namespace std;

constexpr int kMod1 = 1e9 + 7;
constexpr int kBase1 = 337;
constexpr int kMod2 = 1e9 + 9;
constexpr int kBase2 = 331;

int pw[2][500];

int64_t Calc(const string& s) {
  int64_t h1 = 0, h2 = 0;
  for (int i = 0; s[i]; i++) {
    h1 = (h1 + (int64_t)pw[0][i] * s[i]) % kMod1;
    h2 = (h2 + (int64_t)pw[1][i] * s[i]) % kMod2;
  }
  return (h1 << 32) | h2;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int64_t p1 = 1, p2 = 1;
  for (int i = 0; i < 500; i++) {
    pw[0][i] = p1, pw[1][i] = p2;
    p1 = p1 * kBase1 % kMod1;
    p2 = p2 * kBase2 % kMod2;
  }

  string s;
  int n, m;
  cin >> n >> m;
  vector<int64_t> h(n);
  while (n--) {
    cin >> s;
    h[n] = Calc(s);
  }
  sort(h.begin(), h.end());
  int cnt = 0;
  while (m--) {
    cin >> s;
    cnt += binary_search(h.begin(), h.end(), Calc(s));
  }
  cout << cnt;

  return 0;
}
