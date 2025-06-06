// Title : 인사성 밝은 곰곰이
// Link  : https://www.acmicpc.net/problem/25192 
// Time  : 32 ms
// Memory: 8312 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  int cnt = 0;
  unordered_set<string> hs;
  while (n--) {
    string s;
    cin >> s;
    if (s == "ENTER") {
      cnt += hs.size();
      unordered_set<string> tmp;
      hs.swap(tmp);
    } else {
      hs.insert(s);
    }
  }
  cout << cnt + hs.size();

  return 0;
}
