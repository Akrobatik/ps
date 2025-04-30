// Title : Shortest and Longest LIS
// Link  : https://www.acmicpc.net/problem/24834 
// Time  : 32 ms
// Memory: 3428 KB

#include <bits/stdc++.h>

using namespace std;

int memo[200000];

void Min(const string& s) {
  int n = s.size();
  int b = 0, x = n;
  while (b < n) {
    int e = b;
    while (e < n && s[e] == '<') ++e;
    for (int i = e; i >= b; i--) memo[i] = x--;
    b = e + 1;
  }
  for (int i = 0; i < n; i++) cout << memo[i] << " ";
  cout << "\n";
}

void Max(const string& s) {
  int n = s.size();
  int b = 0, x = 0;
  while (b < n) {
    int e = b;
    while (e < n && s[e] == '>') ++e;
    for (int i = e; i >= b; i--) memo[i] = ++x;
    b = e + 1;
  }
  for (int i = 0; i < n; i++) cout << memo[i] << " ";
  cout << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;
  while (t--) {
    int n;
    string s;
    cin >> n >> s;
    s.push_back('x');
    Min(s);
    Max(s);
  }

  return 0;
}
