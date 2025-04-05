// Title : 무한 수열
// Link  : https://www.acmicpc.net/problem/1351
// Time  : 0 ms
// Memory: 2156 KB

#include <bits/stdc++.h>

using namespace std;

int64_t p, q;
unordered_map<int64_t, int64_t> mp;

int64_t GetNth(int64_t nth) {
  if (nth == 0) return 1;
  if (auto it = mp.find(nth); it != mp.end()) return it->second;
  return mp[nth] = GetNth(nth / p) + GetNth(nth / q);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int64_t n;
  cin >> n >> p >> q;
  cout << GetNth(n);

  return 0;
}
