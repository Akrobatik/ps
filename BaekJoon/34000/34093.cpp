// Title : 시간선 통합
// Link  : https://www.acmicpc.net/problem/34093 
// Time  : 88 ms
// Memory: 8392 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<int> arr;
  vector<array<bool, 2>> fwd, bwd;

  vector<int> ans;
  string sns;

  int t;
  cin >> t;
  while (t--) {
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    arr.resize(n + 1);

    for (int i = 1; i <= n; i++) cin >> arr[i];

    fwd.resize(n + 1);
    fwd[0] = {false, false};
    for (int i = 1; i <= n; i++) {
      fwd[i] = fwd[i - 1];
      if (arr[i] < m) fwd[i][0] = true;
      if (arr[i] > m) fwd[i][1] = true;
    }

    bwd.resize(n + 2);
    bwd[n + 1] = {false, false};
    for (int i = n; i >= 1; i--) {
      bwd[i] = bwd[i + 1];
      if (arr[i] < m) bwd[i][0] = true;
      if (arr[i] > m) bwd[i][1] = true;
    }

    int idx = 1;
    while (arr[idx] != m) ++idx;

    int acnt = 0, bcnt = 0;
    if (fwd[idx][0]) ++bcnt;
    if (fwd[idx][1]) ++acnt;
    if (bwd[idx][0]) ++bcnt;
    if (bwd[idx][1]) ++acnt;

    int arem = a - acnt, brem = b - bcnt;
    if (min<int>(arem, brem) < 0) {
      cout << "no\n";
      continue;
    }

    ans.clear();
    sns.clear();
    ans.reserve(n - 1);
    sns.reserve(n - 1);

    auto Push = [&]() {
      if (arem > 0) {
        --arem;
        sns.push_back('m');
      } else {
        --brem;
        sns.push_back('M');
      }
    };

    if (bwd[idx][0] && bwd[idx][1]) {
      int nxt = idx + 1;
      while ((arr[idx] < arr[idx + 1]) == (arr[idx] < arr[nxt])) ++nxt;
      for (int i = nxt; i < n; i++) {
        ans.push_back(nxt);
        Push();
      }
      ans.push_back(nxt - 1);
      if (arr[idx] < arr[idx + 1]) {
        sns.push_back('M');
      } else {
        sns.push_back('m');
      }
      for (int i = idx + 1; i < nxt - 1; i++) {
        ans.push_back(idx + 1);
        Push();
      }
      ans.push_back(idx);
      if (arr[idx] < arr[idx + 1]) {
        sns.push_back('m');
      } else {
        sns.push_back('M');
      }
    } else if (bwd[idx][0] || bwd[idx][1]) {
      for (int i = idx + 1; i < n; i++) {
        ans.push_back(idx + 1);
        Push();
      }
      ans.push_back(idx);
      if (arr[idx] < arr[idx + 1]) {
        sns.push_back('m');
      } else {
        sns.push_back('M');
      }
    }

    if (fwd[idx][0] && fwd[idx][1]) {
      int nxt = idx - 1;
      while ((arr[idx] < arr[idx - 1]) == (arr[idx] < arr[nxt])) --nxt;
      for (int i = 1; i < nxt; i++) {
        ans.push_back(1);
        Push();
      }
      ans.push_back(1);
      if (arr[idx] < arr[idx - 1]) {
        sns.push_back('M');
      } else {
        sns.push_back('m');
      }
      for (int i = nxt + 1; i < idx - 1; i++) {
        ans.push_back(1);
        Push();
      }
      ans.push_back(1);
      if (arr[idx] < arr[idx - 1]) {
        sns.push_back('m');
      } else {
        sns.push_back('M');
      }
    } else if (fwd[idx][0] || fwd[idx][1]) {
      for (int i = 2; i < idx; i++) {
        ans.push_back(1);
        Push();
      }
      ans.push_back(1);
      if (arr[idx] < arr[idx - 1]) {
        sns.push_back('m');
      } else {
        sns.push_back('M');
      }
    }

    cout << "yes\n"
         << sns << "\n";
    for (auto e : ans) cout << e << " ";
    cout << "\n";
  }

  return 0;
}
