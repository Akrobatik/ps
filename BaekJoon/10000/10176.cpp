// Title : Opposite Words
// Link  : https://www.acmicpc.net/problem/10176
// Time  : 0 ms
// Memory: 2028 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  while (n--) {
    string s, s2, s3;
    cin >> s;
    for (auto c : s) {
      if (isalpha(c)) {
        c = tolower(c);
        s2.push_back(c);
        s3.push_back('z' - (c - 'a'));
      }
    }
    sort(s2.begin(), s2.end());
    sort(s3.begin(), s3.end());

    bool ok = true;
    for (int i = 0; ok && i < s2.size(); i++) {
      ok = (s2[i] == s3[i]);
    }
    cout << (ok ? "Yes\n" : "No\n");
  }

  return 0;
}
