// Title : 벚꽃과 단풍
// Link  : https://www.acmicpc.net/problem/33989 
// Time  : 0 ms
// Memory: 2784 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  string s;
  cin >> n >> s;

  vector<int> fwd(n + 1);
  for (int i = 1; i <= n; i++) {
    fwd[i] = fwd[i - 1] + (s[i - 1] == 'B');
  }

  int minn = INT_MAX;
  for (int i = 0; i <= n; i++) {
    int b = i, d = n - i;
    int cb = fwd[i] - fwd[0], cd = (n - i) - (fwd[n] - fwd[i]);
    minn = min<int>(minn, abs(b - cb) + abs(d - cd));
  }
  cout << minn;

  return 0;
}