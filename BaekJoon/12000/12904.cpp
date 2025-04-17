// Title : A와 B
// Link  : https://www.acmicpc.net/problem/12904 
// Time  : 0 ms
// Memory: 2024 KB

#include <bits/stdc++.h>

using namespace std;

void Traverse(const string& s1, const string& s2, int l, int r, bool rev) {
  if (s1.size() == r - l) {
    bool match = true;
    if (rev) {
      for (int i = 0; match && i < s1.size(); i++) {
        match = (s1[i] == s2[r - i - 1]);
      }
    } else {
      for (int i = 0; match && i < s1.size(); i++) {
        match = (s1[i] == s2[l + i]);
      }
    }
    if (match) {
      cout << "1";
      exit(0);
    }
    return;
  }

  if (rev) {
    Traverse(s1, s2, l + 1, r, s2[l] == 'A');
  } else {
    Traverse(s1, s2, l, r - 1, s2[r - 1] == 'B');
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string s1, s2;
  cin >> s1 >> s2;
  Traverse(s1, s2, 0, s2.size(), false);
  cout << "0";

  return 0;
}
