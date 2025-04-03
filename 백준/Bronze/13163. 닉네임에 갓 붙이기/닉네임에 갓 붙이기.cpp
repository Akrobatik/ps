#include <bits/stdc++.h>

using namespace std;

vector<string> Tokenize(string str) {
  vector<string> tokens;
  size_t b = 0, e;
  while ((e = str.find(' ', b)) != string::npos) {
    tokens.push_back(str.substr(b, e - b));
    b = e + 1;
  }
  tokens.push_back(str.substr(b));
  return tokens;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  string s;
  cin >> n;
  getline(cin, s);
  while (n--) {
    getline(cin, s);
    auto tokens = Tokenize(s);
    cout << "god";
    for (int i = 1; i < tokens.size(); i++) {
      cout << tokens[i];
    }
    cout << "\n";
  }

  return 0;
}
