// Title : LCS Making
// Link  : https://www.acmicpc.net/problem/33995 
// Time  : 0 ms
// Memory: 2648 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  string s;
  cin >> n >> k >> s;
  int cnt[26] = {};
  for (auto c : s) ++cnt[c - 'a'];
  
  int minn = *min_element(cnt, cnt + 26);
  cout << (k >= minn);

  return 0;
}
