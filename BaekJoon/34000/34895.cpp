// Title : 이진수 MEX
// Link  : https://www.acmicpc.net/problem/34895 
// Time  : 8 ms
// Memory: 6744 KB

#include <bits/stdc++.h>

using namespace std;

constexpr int kMax = 22;
bool mask[1 << kMax];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  string s;
  cin >> n >> s;

  for (int i = 0; i < n; i++) {
    int val = 0;
    int limit = min<int>(n - i, kMax);
    for (int j = 0; j < limit; j++) {
      val = (val << 1) | (s[i + j] - '0');
      mask[val] = true;
    }
  }

  int mex = 1;
  while (mask[mex]) ++mex;

  string ans = bitset<32>(mex).to_string();
  reverse(ans.begin(), ans.end());
  while (!ans.empty() && ans.back() == '0') ans.pop_back();
  reverse(ans.begin(), ans.end());
  cout << ans;

  return 0;
}