// Title : Rabbit Horse
// Link  : https://www.acmicpc.net/problem/34076 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

constexpr const char* kStr = "rabithorse";

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  if (n <= 10) {
    while (n--) cout << 'X';
    return 0;
  }

  int rem = n - 11, mi;
  int64_t maxx = 0;
  for (int i = 0; i <= rem; i++) {
    int64_t val = (i + 2) * (i + 1) / 2;
    int sum = n - i - 2, one = sum / 9;
    int add = sum - one * 9;
    for (int j = 0; j < 9; j++) {
      int x = one + (j < add);
      val *= x;
    }
    if (maxx < val) maxx = val, mi = i;
  }

  int cnt[10] = {};
  int sum = n - mi - 2, one = sum / 9;
  int add = sum - one * 9;
  for (int i = 0; i < 9; i++) {
    cnt[i] = one + (i < add);
  }
  swap(cnt[2], cnt[9]);
  cnt[2] = mi + 2;

  for (int i = 0; i < 10; i++) {
    while (cnt[i]--) cout << kStr[i];
  }

  return 0;
}
