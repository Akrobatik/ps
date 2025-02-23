#include <bits/stdc++.h>

using namespace std;

constexpr int kMod = 10007;

string s;
int memo[1000][1000];

int Traverse(int b, int e) {
  if (b > e) return 0;
  if (b == e) return 1;
  if (memo[b][e]) return memo[b][e];

  memo[b][e] = (Traverse(b + 1, e) + Traverse(b, e - 1)) % kMod;
  if (s[b] == s[e]) {
    if (++memo[b][e] == kMod) memo[b][e] = 0;
  } else {
    memo[b][e] = (memo[b][e] - Traverse(b + 1, e - 1) + kMod) % kMod;
  }
  return memo[b][e];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> s;
  cout << Traverse(0, s.size() - 1);

  return 0;
}
