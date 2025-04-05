// Title : Report Card Time
// Link  : https://www.acmicpc.net/problem/11367
// Time  : 0 ms
// Memory: 2024 KB

#include <bits/stdc++.h>

using namespace std;

const char* GetGrade(int x) {
  if (x >= 97) return "A+";
  if (x >= 90) return "A";
  if (x >= 87) return "B+";
  if (x >= 80) return "B";
  if (x >= 77) return "C+";
  if (x >= 70) return "C";
  if (x >= 67) return "D+";
  if (x >= 60) return "D";
  return "F";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    string s;
    int n;
    cin >> s >> n;
    cout << s << " " << GetGrade(n) << "\n";
  }

  return 0;
}
