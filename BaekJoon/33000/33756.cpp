// Title : 88888
// Link  : https://www.acmicpc.net/problem/33756 
// Time  : 28 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

bool Check(int64_t x) {
  if (x % 8) return false;

  string s = to_string(x >> 3);
  if (s[0] == '9') return false;
  for (int i = 1; i < s.size(); i++) {
    if (s[i] == '9' || s[i - 1] > s[i]) return false;
  }
  return true;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int64_t x;
    cin >> x;
    cout << (Check(x) ? "Yes\n" : "No\n");
  }

  return 0;
}