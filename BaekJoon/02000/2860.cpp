// Title : 종이에 숫자 쓰기
// Link  : https://www.acmicpc.net/problem/2860 
// Time  : 0 ms
// Memory: 2024 KB

#include <bits/stdc++.h>

using namespace std;

int64_t GCD(int64_t a, int64_t b) {
  while (b) a %= b, swap(a, b);
  return a;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string s1, s2;
  getline(cin, s1, '.');
  getline(cin, s2);

  int64_t cnt = 1;
  for (int i = 0; i < s2.size(); i++) cnt *= 10;
  int64_t sum = cnt * stoi(s1) + stoi(s2);
  int64_t g = GCD(sum, cnt);
  sum /= g, cnt /= g;

  int ans[6] = {};
  int l = sum / cnt, r = l + 1;
  ans[r] = sum - cnt * l, ans[l] = cnt - ans[r];
  for (int i = 1; i <= 5; i++) cout << ans[i] << " ";

  return 0;
}
