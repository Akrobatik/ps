// Title : 치매예방수칙 3．3．3
// Link  : https://www.acmicpc.net/problem/33709
// Time  : 0 ms
// Memory: 2160 KB

#include <bits/stdc++.h>

using namespace std;

vector<string> Tokenize(string str) {
  vector<string> tokens;
  size_t b = 0, e;
  while ((e = str.find_first_of(".|:#", b)) != string::npos) {
    tokens.push_back(str.substr(b, e - b));
    b = e + 1;
  }
  tokens.push_back(str.substr(b));
  return tokens;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  int n;
  cin >> n >> s;
  auto tokens = Tokenize(s);
  int64_t ans = 0;
  for (auto token : tokens) ans += stoi(token);
  cout << ans;

  return 0;
}
