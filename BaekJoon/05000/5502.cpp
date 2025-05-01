// Title : 팰린드롬
// Link  : https://www.acmicpc.net/problem/5502 
// Time  : 336 ms
// Memory: 124284 KB

#include <bits/stdc++.h>

using namespace std;

bool visited[5000][5000];
int memo[5000][5000];

int Traverse(const string& s, int l, int r) {
  if (l >= r) return 0;
  if (visited[l][r]) return memo[l][r];
  visited[l][r] = true;

  auto& res = memo[l][r];
  while (l < r && s[l] == s[r]) ++l, --r;
  if (l >= r) return res = 0;
  return res = min<int>(Traverse(s, l + 1, r), Traverse(s, l, r - 1)) + 1;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  string s;
  cin >> n >> s;
  cout << Traverse(s, 0, n - 1);

  return 0;
}
