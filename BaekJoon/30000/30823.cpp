// Title : 건공문자열
// Link  : https://www.acmicpc.net/problem/30823 
// Time  : 12 ms
// Memory: 2912 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  string s;
  cin >> n >> k >> s;
  --k;
  for (int i = k; i < n; i++) cout << s[i];
  if ((n - k + 1) & 1) {
    for (int i = 0; i < k; i++) cout << s[i];
  } else {
    while (k--) cout << s[k];
  }

  return 0;
}
