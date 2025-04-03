#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  while (getline(cin, s) && s.compare("EOI") != 0) {
    for (auto& c : s) {
      if (isalpha(c)) c = tolower(c);
    }

    cout << (s.find("nemo") != string::npos ? "Found\n" : "Missing\n");
  }

  return 0;
}
