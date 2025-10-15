// Title : GPS Encoding
// Link  : https://www.acmicpc.net/problem/2235 
// Time  : 0 ms
// Memory: 2024 KB

#include <bits/stdc++.h>

using namespace std;

string table;

string Find(const string& s) {
  int n = s.size();
  vector<string> memo(n + 1);
  for (int i = 0; i < n; i++) {
    memo[i + 1] = memo[i];
    memo[i + 1].push_back(table[s[i] - '0']);
    int x = (i > 0 ? stoi(s.substr(i - 1, 2)) : 26);
    if (x < 26) {
      string tmp = memo[i - 1];
      tmp.push_back(table[x]);
      int nf = memo[i + 1].size();
      int nc = tmp.size();
      if (nf > nc || (nf == nc && tmp > memo[i + 1])) memo[i + 1] = tmp;
    }
  }
  return memo[n];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  for (int t = 1;; t++) {
    cin >> table;
    if (table.size() < 26) break;

    if (t > 1) cout << "\n";
    cout << "Problem " << t << "\n";
    string s;
    while (cin >> s && s != "0") {
      cout << Find(s) << "\n";
    }
  }

  return 0;
}