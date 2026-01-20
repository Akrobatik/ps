// Title : Palindrome Partition
// Link  : https://www.acmicpc.net/problem/35141 
// Time  : 4 ms
// Memory: 2532 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  cin >> s;

  int cnt[256] = {};
  for (auto c : s) ++cnt[c];

  vector<int> arr;
  for (int i = 'a'; i <= 'z'; i++) {
    if (cnt[i] & 1) arr.push_back(i);
  }

  cout << max<int>(arr.size(), 1) << "\n";

  char ch = (arr.empty() ? 0 : arr[0]);
  for (int i = 1; i < arr.size(); i++) {
    cout << (char)(arr[i]) << "\n";
  }

  for (int i = 'a'; i <= 'z'; i++) {
    int half = cnt[i] >> 1;
    while (half--) cout << (char)(i);
  }
  if (ch) cout << ch;
  for (int i = 'z'; i >= 'a'; i--) {
    int half = cnt[i] >> 1;
    while (half--) cout << (char)(i);
  }

  return 0;
}