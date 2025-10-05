// Title : 문자열
// Link  : https://www.acmicpc.net/problem/1352 
// Time  : 0 ms
// Memory: 2156 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<vector<bool>> memo(n + 1, vector<bool>(n + 1));
  memo[0][0] = true;
  for (int i = 1; i <= n; i++) {
    int add = i - 1;
    for (int j = 0; j <= n; j++) {
      if (j + 1 <= n && memo[i - 1][j + 1]) {
        memo[i][j] = true;
      } else if (j - add >= 0 && memo[i - 1][j - add]) {
        memo[i][j] = true;
      }
    }
  }

  if (!memo[n][0]) {
    cout << "-1";
    return 0;
  }

  vector<vector<bool>> bt(n + 1, vector<bool>(n + 1));
  bt[n][0] = true;
  for (int i = n - 1; i >= 0; i--) {
    int add = i;
    for (int j = 0; j <= n; j++) {
      if (!memo[i][j]) continue;
      if (j - 1 >= 0 && bt[i + 1][j - 1]) bt[i][j] = true;
      if (j + add <= n && bt[i + 1][j + add]) bt[i][j] = true;
    }
  }

  vector<int> arr;
  int cur = 0;
  for (int i = 0; i < n; i++) {
    if (cur - 1 >= 0 && bt[i + 1][cur - 1]) {
      --cur;
    } else {
      arr.push_back(i + 1);
      cur += i;
    }
  }
  reverse(arr.begin(), arr.end());

  char base = 'A';
  priority_queue<char, vector<char>, greater<char>> pq;
  for (int i = 1; i <= n; i++) {
    if (!arr.empty() && arr.back() == i) {
      arr.pop_back();
      char ch = base++;
      cout << ch;
      for (int j = 1; j < i; j++) pq.push(ch);
    } else {
      cout << pq.top();
      pq.pop();
    }
  }

  return 0;
}