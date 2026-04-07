// Title : 루미와 블록 쌓기 게임
// Link  : https://www.acmicpc.net/problem/35481 
// Time  : 0 ms
// Memory: 2024 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<string> mat(20);
  for (auto& s : mat) cin >> s;

  int pos[20] = {0, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};

  int k = 1;
  while (k <= 19) {
    auto& s = mat[20 - k];

    int cnt = count(s.begin(), s.end(), '.');
    int p = pos[k];
    if (cnt != 1 || s[p] != '.' || mat[19 - k][p] != '#') break;

    ++k;
  }

  if (2 <= k && k <= 10) {
    cout << 11 - k;
  } else if (11 <= k && k <= 19) {
    cout << "S" << k - 10;
  } else if (k == 20) {
    cout << "GM";
  } else {
    cout << "X";
  }

  return 0;
}