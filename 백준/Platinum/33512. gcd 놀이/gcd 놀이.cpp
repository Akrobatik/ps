#include <bits/stdc++.h>

using namespace std;

int64_t memo[100001];
int64_t fwd[100001], bwd[100001];

int Calc() {
  memset(bwd, 0, sizeof(bwd));

  for (int64_t i = 1; i <= 100000; i++) {
    int64_t cnt = 0;
    for (int64_t j = i; j <= 100000; j += i) cnt += memo[j];
    fwd[i] = cnt * (cnt - 1) / 2;
  }

  for (int64_t i = 100000; i >= 1; i--) {
    int64_t cnt = 0;
    for (int64_t j = i << 1; j <= 100000; j += i) {
      cnt += bwd[j];
    }
    bwd[i] = fwd[i] - cnt;
  }

  int minn = 1;
  while (bwd[minn] == 0) ++minn;

  int maxx = 100000;
  while (bwd[maxx] == 0) --maxx;

  return maxx - minn;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    memset(memo, 0, sizeof(memo));

    int n, k, maxx = 0;
    cin >> n >> k;
    while (n--) {
      int x;
      cin >> x;
      ++memo[x];
      maxx = max<int>(maxx, x);
    }

    int ans = 0;
    if (k == 0) {
      ans = Calc();
    } else if (k == 1) {
      ++memo[maxx];
      ans = max<int>(ans, Calc());
      --memo[maxx];

      ++memo[1];
      ans = max<int>(ans, Calc());
      --memo[1];
    } else if (k == 2) {
      ++memo[maxx], ++memo[1];
      ans = max<int>(ans, Calc());
      --memo[maxx], --memo[1];
      for (int i = 99991; i <= 100000; i++) {
        memo[i] += 2;
        ans = max<int>(ans, Calc());
        memo[i] -= 2;
      }
    } else {
      ans = 99999;
    }
    cout << ans << "\n";
  }

  return 0;
}
