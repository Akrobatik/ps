// Title : 알파벳 점수 계산기
// Link  : https://www.acmicpc.net/problem/34553 
// Time  : 0 ms
// Memory: 2300 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  cin >> s;
  int n = s.size();

  int64_t cur = 1, sum = 1;
  for (int i = 1; i < n; i++) {
    if (s[i] > s[i - 1]) {
      ++cur;
    } else {
      cur = 1;
    }
    sum += cur;
  }
  cout << sum;

  return 0;
}