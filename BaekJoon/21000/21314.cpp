// Title : 민겸 수
// Link  : https://www.acmicpc.net/problem/21314 
// Time  : 0 ms
// Memory: 2024 KB

#include <bits/stdc++.h>

using namespace std;

string MaxMK(const string& s) {
  string res;
  res.reserve(s.size());
  int cnt = 0;
  for (auto c : s) {
    if (c == 'M') {
      ++cnt;
    } else {
      res.push_back('5');
      res.resize(res.size() + cnt, '0');
      cnt = 0;
    }
  }
  if (cnt) {
    res.resize(res.size() + cnt, '1');
  }
  return res;
}

string MinMK(const string& s) {
  string res;
  res.reserve(s.size());
  int cnt = 0;
  for (auto c : s) {
    if (c == 'M') {
      ++cnt;
    } else {
      if (cnt != 0) {
        res.push_back('1');
        res.resize(res.size() + cnt - 1, '0');
      }
      res.push_back('5');
      cnt = 0;
    }
  }
  if (cnt) {
    res.push_back('1');
    res.resize(res.size() + cnt - 1, '0');
  }
  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  cin >> s;
  cout << MaxMK(s) << "\n"
       << MinMK(s);

  return 0;
}
