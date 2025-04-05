// Title : 치킨 배달
// Link  : https://www.acmicpc.net/problem/15686
// Time  : 4 ms
// Memory: 2028 KB

#include <bits/stdc++.h>

using namespace std;

int n_chicken, n_house;
int8_t chickens[13][2];
int8_t house[2500][2];
int8_t memo[2500];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      char c;
      cin >> c;
      if (c == '1') {
        house[n_house][0] = i;
        house[n_house][1] = j;
        n_house++;
      } else if (c == '2') {
        chickens[n_chicken][0] = i;
        chickens[n_chicken][1] = j;
        n_chicken++;
      }
    }
  }

  vector<uint8_t> masks(n_chicken, 0);
  memset(masks.data() + n_chicken - m, 1, m);

  int ans = INT_MAX;
  do {
    memset(memo, 0, n_house);
    for (int i = 0; i < n_chicken; i++) {
      if (masks[i]) {
        int cx = chickens[i][0];
        int cy = chickens[i][1];
        for (int j = 0; j < n_house; j++) {
          int d = abs(house[j][0] - cx) + abs(house[j][1] - cy);
          if (memo[j] == 0 || memo[j] > d) memo[j] = d;
        }
      }
    }
    int sum = accumulate(memo, memo + n_house, 0);
    if (ans > sum) ans = sum;
  } while (next_permutation(masks.begin(), masks.end()));

  cout << ans << endl;

  return 0;
}
