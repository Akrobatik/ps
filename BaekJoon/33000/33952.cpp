// Title : PPC와 CPP
// Link  : https://www.acmicpc.net/problem/33952 
// Time  : 4 ms
// Memory: 2912 KB

#include <bits/stdc++.h>

using namespace std;

bool Check(string_view sv) {
  if (sv.empty() || sv[0] == 'C') return true;

  int cnt = 0;
  for (int i = 0; i < sv.size(); i++) {
    if (sv[i] == 'C') {
      cnt -= 2;
      if (cnt == 0) return Check(sv.substr(i + 1));
    } else {
      ++cnt;
    }
  }
  return false;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  string s;
  cin >> n >> s;

  int nc = count(s.begin(), s.end(), 'C');
  if (nc * 3 != n) {
    cout << "NO";
    return 0;
  }

  cout << (Check(s) ? "YES" : "NO");

  return 0;
}
