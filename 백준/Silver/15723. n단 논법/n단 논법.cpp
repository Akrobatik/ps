#include <bits/stdc++.h>

using namespace std;

int memo[26];

bool Check(int a, int b) {
  if (a == b) return true;
  if (memo[a] & (1 << b)) return true;
  for (int i = 0; i < 26; i++) {
    if (!(memo[a] & (1 << i))) continue;
    if (Check(i, b)) return true;
  }
  return false;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  while (n--) {
    char a, _1, _2, b;
    cin >> a >> _1 >> _2 >> b;
    memo[a - 'a'] |= (1 << b - 'a');
  }

  int m;
  cin >> m;
  while (m--) {
    char a, _1, _2, b;
    cin >> a >> _1 >> _2 >> b;
    cout << (Check(a - 'a', b - 'a') ? "T\n" : "F\n");
  }

  return 0;
}
