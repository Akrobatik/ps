// Title : 암호 해독가 최준민
// Link  : https://www.acmicpc.net/problem/2815 
// Time  : 88 ms
// Memory: 11300 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  unordered_map<string, int> memo;

  string s;
  vector<int> arr, brr;
  while (cin >> s && s != "$") {
    if (!memo.contains(s)) memo[s] = memo.size();
    arr.push_back(memo[s]);
  }
  vector<int> axr(arr.size()), amr(memo.size(), -1);
  for (int i = 0; i < arr.size(); i++) {
    axr[i] = amr[arr[i]];
    amr[arr[i]] = i;
  }

  memo.clear();
  while (cin >> s && s != "$") {
    if (!memo.contains(s)) memo[s] = memo.size();
    brr.push_back(memo[s]);
  }
  vector<int> bxr(brr.size()), bmr(memo.size(), -1);
  for (int i = 0; i < brr.size(); i++) {
    bxr[i] = bmr[brr[i]];
    bmr[brr[i]] = i;
  }

  auto MatchPat = [&](int i, int j) {
    int d = i - j;
    if (bxr[j] == -1) return bxr[i] < d;
    return bxr[i] - d == bxr[j];
  };

  vector<int> table(brr.size());
  for (int i = 1, j = 0; i < brr.size(); i++) {
    while (j && !MatchPat(i, j)) j = table[j - 1];
    if (MatchPat(i, j)) table[i] = ++j;
  }

  auto MatchStr = [&](int i, int j) {
    int d = i - j;
    if (bxr[j] == -1) return axr[i] < d;
    return axr[i] - d == bxr[j];
  };

  for (int i = 0, j = 0; i < arr.size(); i++) {
    while (j && !MatchStr(i, j)) j = table[j - 1];
    if (MatchStr(i, j)) ++j;
    if (j == brr.size()) {
      cout << (i - j + 2);
      break;
    }
  }

  return 0;
}