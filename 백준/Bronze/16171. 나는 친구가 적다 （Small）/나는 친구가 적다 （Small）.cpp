#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string s1, s2, s3;
  cin >> s1 >> s2;
  for (auto c : s1) {
    if ('0' <= c && c <= '9') continue;
    s3.push_back(c);
  }
  cout << (s3.find(s2) != string::npos ? 1 : 0);

  return 0;
}
