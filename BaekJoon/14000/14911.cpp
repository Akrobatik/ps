// Title : 궁합 쌍 찾기
// Link  : https://www.acmicpc.net/problem/14911 
// Time  : 0 ms
// Memory: 2084 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  getline(cin, s);
  int x;
  cin >> x;

  istringstream iss(s);
  vector<int> arr;
  int y;
  while (iss >> y) arr.push_back(y);
  sort(arr.begin(), arr.end());
  set<pair<int, int>> memo;
  int cnt = 0;
  for (int i = 0; i < arr.size(); i++) {
    for (int j = i + 1; j < arr.size(); j++) {
      if (arr[i] + arr[j] == x) {
        if (memo.contains({arr[i], arr[j]})) continue;
        memo.insert({arr[i], arr[j]});
        cout << arr[i] << " " << arr[j] << "\n";
        ++cnt;
      }
    }
  }
  cout << cnt;

  return 0;
}
