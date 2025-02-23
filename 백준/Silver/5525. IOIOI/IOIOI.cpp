#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  string s, token;
  cin >> s;
  token.resize(n * 2 + 1);
  token[0] = 'I';
  for (int i = 0; i < n; i++) {
    token[i * 2 + 1] = 'O';
    token[i * 2 + 2] = 'I';
  }

  int cnt = 0, b = 0;
  while ((b = s.find(token, b)) != string::npos) {
    ++cnt;
    b += 2;
  }
  cout << cnt;

  return 0;
}
