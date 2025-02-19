#include <bits/stdc++.h>

using namespace std;

int pts[2047][11];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  auto ptr = (int*)pts;
  for (int i = 0; i < 2047 * 11; i++) cin >> *ptr++;

  int cnt[11] = {}, pt1[11], pt2[11];
  for (int i = 0; i < 11; i++) pt1[i] = pts[0][i];
  for (int i = 0; i < 11; i++) {
    for (int j = 1; j < 2047; j++) {
      if (pt1[i] == pts[j][i]) continue;
      pt2[i] = pts[j][i];
      break;
    }
  }

  for (int i = 0; i < 2047; i++) {
    for (int j = 0; j < 11; j++) {
      cnt[j] += ((pts[i][j] == pt1[j]) << 1) - 1;
    }
  }

  for (int i = 0; i < 11; i++) {
    cout << ((cnt[i] ^ 1) ? pt1[i] : pt2[i]) << " ";
  }

  return 0;
}
