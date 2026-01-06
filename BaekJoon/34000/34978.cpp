// Title : 맞혀보세요~
// Link  : https://www.acmicpc.net/problem/34978 
// Time  : 0 ms
// Memory: 2024 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<vector<int>> mat(26, vector<int>(26, 1));
  while (n--) {
    char a;
    int m;
    cin >> a >> m;
    a -= 'a';
    mat[a].assign(26, 0);
    while (m--) {
      char b;
      cin >> b, b -= 'a';
      mat[a][b] = 1;
    }
  }

  string s;
  cin >> s;
  int ns = s.size();
  for (int i = 0; i + 1 < ns; i++) {
    int l = s[i] - 'a', r = s[i + 1] - 'a';
    if (mat[l][r]) continue;
    cout << "no";
    return 0;
  }
  cout << "yes";

  return 0;
}