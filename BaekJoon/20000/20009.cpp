// Title : 형곤이의 소개팅
// Link  : https://www.acmicpc.net/problem/20009 
// Time  : 8 ms
// Memory: 2428 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  unordered_map<string, int> hm;
  vector<string> aname(n + 1), bname(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> aname[i];
    hm[aname[i]] = i;
  }
  for (int i = 1; i <= n; i++) {
    cin >> bname[i];
    hm[bname[i]] = i;
  }

  vector<int> ids(n + 1, 1), arr(n + 1), brr(n + 1);
  vector<vector<int>> axr(n + 1, vector<int>(n + 1));
  vector<vector<int>> bxr(n + 1, vector<int>(n + 1));

  for (int i = 1; i <= n; i++) {
    string s;
    cin >> s;
    int id = hm[s];
    for (int j = 1; j <= n; j++) {
      cin >> s;
      axr[id][j] = hm[s];
    }
  }

  for (int i = 1; i <= n; i++) {
    string s;
    cin >> s;
    int id = hm[s];
    for (int j = 1; j <= n; j++) {
      cin >> s;
      bxr[id][hm[s]] = j;
    }
  }

  queue<int> q;
  for (int i = 1; i <= n; i++) q.push(i);

  while (!q.empty()) {
    int a = q.front();
    q.pop();

    if (ids[a] > n) continue;

    int b = axr[a][ids[a]++];
    if (brr[b] == 0) {
      arr[a] = b;
      brr[b] = a;
    } else {
      int cur = bxr[b][a], old = bxr[b][brr[b]];
      if (cur < old) {
        arr[brr[b]] = 0;
        q.push(brr[b]);
        arr[a] = b;
        brr[b] = a;
      } else {
        q.push(a);
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    int j = arr[i];
    cout << aname[i] << " " << bname[j] << "\n";
  }

  return 0;
}