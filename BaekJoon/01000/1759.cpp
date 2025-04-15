// Title : 암호 만들기
// Link  : https://www.acmicpc.net/problem/1759 
// Time  : 0 ms
// Memory: 2168 KB

#include <bits/stdc++.h>

using namespace std;

bool IsVowel(int ch) {
  return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}

bool Check(const string& s) {
  int cnt[2] = {};
  for (auto c : s) ++cnt[IsVowel(c)];
  return cnt[0] >= 2 && cnt[1] >= 1;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int l, c;
  cin >> l >> c;
  vector<char> digits(c);
  for (auto& c : digits) cin >> c;
  sort(digits.begin(), digits.end());
  vector<bool> mask(c, true);
  for (int i = 0; i < c - l; i++) mask[i] = false;

  vector<string> ans;

  string s;
  s.resize(l);
  do {
    auto it = s.begin();
    for (int i = 0; i < c; i++) {
      if (mask[i]) *it++ = digits[i];
    }
    if (Check(s)) ans.push_back(s);
  } while (next_permutation(mask.begin(), mask.end()));

  sort(ans.begin(), ans.end());

  for (auto& s : ans) {
    cout << s << "\n";
  }

  return 0;
}
