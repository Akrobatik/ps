// Title : KSA 문자열 3
// Link  : https://www.acmicpc.net/problem/35297 
// Time  : 4 ms
// Memory: 2912 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  cin >> s;

  int n = s.size();
  int key = (n + 2) % 3, cnt = 0;

  for (int i = n - 1; i >= 0; i--) {
    int pr = (n - i - 1) & 1;
    if ((cnt & 1) == pr && s[i] == "KSA"[key]) {
      ++cnt, key = (key + 2) % 3;
    }
  }
  cout << (n - cnt) * 2;

  return 0;
}