// Title : 가장 많은 글자
// Link  : https://www.acmicpc.net/problem/1371 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int memo[26] = {};
  int maxx = 0;
  char c;
  while (cin >> c) {
    if (isalpha(c)) {
      maxx = max<int>(maxx, ++memo[c - 'a']);
    }
  }

  for (int i = 0; i < 26; i++) {
    if (memo[i] != maxx) continue;
    cout << (char)(i + 'a');
  }

  return 0;
}
