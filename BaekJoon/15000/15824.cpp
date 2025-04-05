// Title : 너 봄에는 캡사이신이 맛있단다
// Link  : https://www.acmicpc.net/problem/15824
// Time  : 60 ms
// Memory: 11400 KB

#include <bits/stdc++.h>

using namespace std;

constexpr int64_t kMod = 1000000007;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int64_t> vec(n);
  for (int i = 0; i < n; i++) cin >> vec[i];
  sort(vec.begin(), vec.end());
  vector<int64_t> forwards(n), backwards(n);
  partial_sum(vec.begin(), vec.end(), forwards.begin());
  partial_sum(vec.rbegin(), vec.rend(), backwards.begin());
  vector<int64_t> power(n - 1);
  if (n != 1) {
    power[n - 2] = 1;
    for (int i = n - 2; i > 0; i--) power[i - 1] = (power[i] << 1) % kMod;
  }

  int64_t sum = 0;
  for (int i = 0; i < n - 1; i++) sum = (sum + ((abs(forwards[i] - backwards[i]) % kMod) * power[i])) % kMod;
  cout << sum;

  return 0;
}
