// Title : 모음의 개수
// Link  : https://www.acmicpc.net/problem/1264 
// Time  : 0 ms
// Memory: 2024 KB

#include <bits/stdc++.h>

using namespace std;

constexpr const char kMask[] = "aeiou";

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  while (getline(cin, s) && s != "#") {
    int cnt = 0;
    for (auto c : s) {
      for (int i = 0; i < 5; i++) {
        if (isalpha(c)) cnt += (tolower(c) == kMask[i]);
      }
    }
    cout << cnt << "\n";
  }

  return 0;
}