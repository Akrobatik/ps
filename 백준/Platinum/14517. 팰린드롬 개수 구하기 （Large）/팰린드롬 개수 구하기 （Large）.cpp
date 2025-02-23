#include <bits/stdc++.h>

using namespace std;

constexpr int kMod = 10007;

string s;
int memo[1000][1000];

int Traverse(int b, int e) {
  if (b > e) return 0;
  if (b == e) return 1;

  auto& v = memo[b][e];
  if (v != -1) return v;

  v = Traverse(b + 1, e) + Traverse(b, e - 1);
  v += kMod - Traverse(b + 1, e - 1);
  if (s[b] == s[e]) v += Traverse(b + 1, e - 1) + 1;
  return v %= kMod;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  memset(memo, -1, sizeof(memo));

  cin >> s;
  cout << Traverse(0, s.size() - 1);

  return 0;
}
