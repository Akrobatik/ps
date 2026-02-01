// Title : Hidden Sequence
// Link  : https://www.acmicpc.net/problem/35199 
// Time  : 4 ms
// Memory: 3572 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string s1, s2, s3;
  cin >> s1 >> s2 >> s3;

  vector<int> brr{0}, crr{0};

  int cnt = 0, all = 0;
  for (auto c : s2) {
    if (c == '1') {
      ++all;
      ++cnt;
    } else {
      brr.push_back(brr.back() + cnt);
      cnt = 0;
    }
  }

  cnt = 0;
  for (auto c : s3) {
    if (c == '1') {
      ++cnt;
    } else {
      crr.push_back(crr.back() + cnt);
      cnt = 0;
    }
  }

  cnt = 0;
  string s;
  int bidx = 0, cidx = 0;
  for (char c : s1) {
    int x;
    if (c == '3') {
      x = brr[++bidx];
    } else {
      x = crr[++cidx];
    }
    while (cnt < x) {
      s.push_back('1');
      ++cnt;
    }
    s.push_back(c);
  }

  while (cnt < all) {
    s.push_back('1');
    ++cnt;
  }
  cout << s;

  return 0;
}