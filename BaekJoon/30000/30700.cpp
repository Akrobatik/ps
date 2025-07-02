// Title : KOREA 문자열 만들기
// Link  : https://www.acmicpc.net/problem/30700 
// Time  : 0 ms
// Memory: 2024 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  cin >> s;
  int cnt = 0;
  for (auto c :s) {
    cnt += (c == "KOREA"[cnt % 5]);
  }
  cout << cnt;

  return 0;
}
