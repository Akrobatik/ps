// Title : DNA
// Link  : https://www.acmicpc.net/problem/21855
// Time  : 0 ms
// Memory: 2172 KB

#include <bits/stdc++.h>

using namespace std;

int64_t seed;

int Rand() {
  seed = seed * 214013 + 2531011;
  return (seed >> 16) & 0x7FFF;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int x = Rand();
  int t = x * 111 - x * (int)sqrt(x);
  while (t--) Rand();
  seed = Rand();

  int m = Rand();
  unordered_set<int> st;
  while (st.size() < 1000) {
    st.insert(Rand() % (m + 1));
  }

  vector<int> arr;
  for (auto x : st) {
    arr.push_back(m | (x << 10));
    arr.push_back((m << 10) | x);
  }

  for (auto e : arr) cout << e << "\n";

  return 0;
}
