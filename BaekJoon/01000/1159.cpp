// Title : 농구 경기
// Link  : https://www.acmicpc.net/problem/1159
// Time  : 0 ms
// Memory: 2024 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int memo[26] = {};
  int n;
  cin >> n;
  while (n--) {
    string s;
    cin >> s;
    ++memo[s.front() - 'a'];
  }

  int cnt = 0;
  for (int i = 0; i < 26; i++) {
    if (memo[i] < 5) continue;
    cout << (char)(i + 'a');
    ++cnt;
  }
  if (cnt == 0) cout << "PREDAJA";

  return 0;
}
