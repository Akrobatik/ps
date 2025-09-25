// Title : 스러피
// Link  : https://www.acmicpc.net/problem/14906 
// Time  : 0 ms
// Memory: 2176 KB

#include <bits/stdc++.h>

using namespace std;

bool C1(const string& s) {
  return regex_match(s, regex(R"(^[DE]F+([DE]F+)*G$)"));
}

bool C2(const string& s) {
  if (s.size() <= 2) return s.compare("AH") == 0;

  smatch sm;
  if (regex_search(s, sm, regex(R"(^AB.*C$)"))) {
    string ss = sm[0];
    return C2(ss.substr(2, ss.size() - 3));
  }
  if (regex_search(s, sm, regex(R"(^A.*C$)"))) {
    string ss = sm[0];
    return C1(ss.substr(1, ss.size() - 2));
  }
  return false;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  cout << "SLURPYS OUTPUT\n";
  while (t--) {
    string s;
    cin >> s;
    int n = s.size();

    bool ok = false;
    for (int i = 0; !ok && i < n; i++) {
      string s1 = s.substr(0, i), s2 = s.substr(i);
      ok = C2(s1) && C1(s2);
    }
    cout << (ok ? "YES\n" : "NO\n");
  }
  cout << "END OF OUTPUT";

  return 0;
}
