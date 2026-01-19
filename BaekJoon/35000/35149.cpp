// Title : NEMODEMIC
// Link  : https://www.acmicpc.net/problem/35149 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  int cnt[7] = {};
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      char c;
      cin >> c;
      switch (c) {
        case '.': {
          ++cnt[0];
        } break;

        case '#': {
          ++cnt[1];
        } break;

        case 'U':
        case 'D':
        case 'L':
        case 'R': {
          ++cnt[2];
        } break;

        case 'A': {
          ++cnt[3];
        } break;

        case 'V': {
          ++cnt[4];
        } break;

        case 'S': {
          ++cnt[5];
        } break;

        case 'E': {
          ++cnt[6];
        } break;
      }
    }
  }

  int lv = -1;
  if (cnt[1] <= 1 && cnt[2] <= 1 && cnt[3] == 0 && cnt[4] == 0 && cnt[5] == 1 && cnt[6] == 1) {
    lv = 1;
  } else if (cnt[3] == 0 && cnt[4] == 0 && cnt[5] == 1 && cnt[6] == 1) {
    lv = 2;
  } else if (cnt[3] == 0 && cnt[5] == 1 && cnt[6] == 1) {
    lv = 3;
  } else if (cnt[5] == 1 && cnt[6] == 1) {
    lv = 4;
  }
  cout << lv;

  return 0;
}