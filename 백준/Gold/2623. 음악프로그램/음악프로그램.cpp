#include <bits/stdc++.h>

using namespace std;

int memo[1001];
vector<short> conds[1001];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int l;
    cin >> l;
    vector<short> seq;
    seq.resize(l);
    for (int j = 0; j < l; j++) cin >> seq[j];

    for (int j = 0; j < l - 1; j++) {
      for (int k = j + 1; k < l; k++) {
        ++memo[seq[k]];
        conds[seq[j]].push_back(seq[k]);
      }
    }
  }

  vector<short> ans;
  ans.reserve(n - 1);
  queue<short> q;
  short cnt = 0;
  for (int i = 1; i <= n; i++) {
    if (memo[i] == 0) {
      q.push(i);
      ++cnt;
    }
  }
  while (!q.empty()) {
    short id = q.front();
    q.pop();

    ans.push_back(id);
    for (auto cid : conds[id]) {
      if (--memo[cid] == 0) {
        q.push(cid);
        ++cnt;
      }
    }
  }

  if (cnt != n) {
    cout << 0 << "\n";
  } else {
    for (short id : ans) {
      cout << id << "\n";
    }
  }

  return 0;
}
