// Title : Hashing
// Link  : https://www.acmicpc.net/problem/15829
// Time  : 0 ms
// Memory: 2024 KB

#include <bits/stdc++.h>

using namespace std;

constexpr int64_t kMod = 1234567891;
constexpr int64_t kBase = 31;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  string s;
  cin >> n >> s;
  int64_t hash = 0;
  for (auto it = s.rbegin(); it != s.rend(); ++it) {
    hash = ((hash * kBase) + *it - 'a' + 1) % kMod;
  }
  cout << hash;

  return 0;
}
