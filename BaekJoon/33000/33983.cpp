// Title : 물과 응애
// Link  : https://www.acmicpc.net/problem/33983 
// Time  : 4 ms
// Memory: 2912 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  string s;
  cin >> n >> s;
  if (n % 3) {
    cout << "mix";
    return 0;
  }
  int bound = n / 3;

  int cnt = 0;
  for (auto c : s) {
    if (c == 'H') {
      ++cnt;
    } else {
      --cnt;
    }
    if (cnt < 0) {
      cout << "mix";
      return 0;
    }
  }

  if (bound != cnt) {
    cout << "mix";
    return 0;
  }

  cnt = 0;
  for (auto c : views::reverse(s)) {
    if (c == 'H') {
      ++cnt;
    } else {
      --cnt;
    }
    if (cnt < 0) {
      cout << "mix";
      return 0;
    }
  }
  cout << "pure";

  return 0;
}
