// Title : Bisecting Bargain
// Link  : https://www.acmicpc.net/problem/35073 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

constexpr int kArr[] = {1, 2, 5, 10, 20, 50, 100, 200, 500};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  int ub = n / 500, cnt[9];
  bool ok = true;
  for (int f = 0; ok && f <= ub; f++) {
    int rem = n - f * 500;
    cnt[8] = f;
    for (int i = 7; i >= 0; i--) {
      int x = rem / kArr[i];
      cnt[i] = x;
      rem -= x * kArr[i];
    }

    ok = [&]() {
      if (~n & 1) {
        bitset<5001> memo;
        memo.set(0);
        for (int i = 0; i < 9; i++) {
          for (int j = 0; j < cnt[i]; j++) {
            memo |= (memo << kArr[i]);
          }
        }
        return memo.test(n >> 1);
      }
      return false;
    }();
  }

  if (ok) {
    cout << "splittable";
  } else {
    int all = 0;
    for (auto e : cnt) all += e;
    cout << all << "\n";
    for (int i = 0; i < 9; i++) {
      for (int j = 0; j < cnt[i]; j++) {
        cout << kArr[i] << " ";
      }
    }
  }

  return 0;
}