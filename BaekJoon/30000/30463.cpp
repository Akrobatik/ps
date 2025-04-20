// Title : K-문자열
// Link  : https://www.acmicpc.net/problem/30463 
// Time  : 84 ms
// Memory: 2028 KB

#include <bits/stdc++.h>

using namespace std;

int cnt[1024];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;
  while (n--) {
    bitset<10> bits;
    string s;
    cin >> s;
    for (auto c : s) bits.set(c - '0');
    ++cnt[bits.to_ulong()];
  }

  int64_t sum = 0;
  for (int i = 0; i < 1024; i++) {
    bitset<10> b1(i);
    if (b1.count() == k && cnt[i]) sum += (int64_t)cnt[i] * (cnt[i] - 1) / 2;
    for (int j = i + 1; j < 1024; j++) {
      bitset<10> b2(j);
      b2 |= b1;
      if (b2.count() == k) sum += (int64_t)cnt[i] * cnt[j];
    }
  }
  cout << sum;

  return 0;
}
