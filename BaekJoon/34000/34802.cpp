// Title : 강의실 들어가기
// Link  : https://www.acmicpc.net/problem/34802 
// Time  : 0 ms
// Memory: 2024 KB

#include <bits/stdc++.h>

using namespace std;

int64_t Read() {
  string s;
  cin >> s;
  int hh = stoi(s.substr(0, 2));
  int mm = stoi(s.substr(3, 2));
  int ss = stoi(s.substr(6, 2));
  return hh * 3600 + mm * 60 + ss;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int64_t st = Read(), en = Read();
  int64_t dt = en - st;

  if (dt < 0) {
    cout << "0";
  } else {
    int64_t org, k;
    cin >> org >> k;

    cout << (org * (100 - k) <= dt * 100);
  }

  return 0;
}