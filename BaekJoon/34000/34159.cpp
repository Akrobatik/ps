// Title : 감그레이
// Link  : https://www.acmicpc.net/problem/34159 
// Time  : 444 ms
// Memory: 30220 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<int> alives(n);
  iota(alives.begin(), alives.end(), 1);
  vector<int> res(n + 1), queries(n);
  vector<bool> out(n + 1);

  auto Kill = [&](int x) {
    cout << "! " << x << endl;
    out[x] = true;
    auto it = lower_bound(alives.begin(), alives.end(), x);
    alives.erase(it);

    int color;
    cin >> color;
    return color;
  };

  auto Query = [&]() {
    for (int i = 1, j = 0; i <= n; i++) {
      if (out[i]) {
        cout << "? 0 0" << endl;
      } else {
        cout << "? " << queries[j++] << " 1" << endl;
      }
    }

    for (int i = 1; i <= n; i++) {
      cin >> res[i];
    }
  };

  int key = 0;
  while (key == 0 && alives.size() >= 2) {
    int na = alives.size();
    queries.resize(na);
    queries[0] = alives.back();
    for (int i = 1; i < na; i++) {
      queries[i] = alives[0];
    }
    Query();

    bool ok = false;
    for (int i = 1; i < na; i++) {
      if (res[alives[i]] != 1) continue;

      ok = true;
      int color = Kill(alives[i]);
      if (color == 1) key = alives[0];
      break;
    }

    if (ok) continue;

    int color = Kill(alives[0]);
    if (color == 1) break;
  }

  if (key == 0) {
    while (!alives.empty()) {
      int na = alives.size();
      queries.resize(na);
      for (int i = 0; i < na; i++) {
        queries[i] = alives[i];
      }
      Query();

      Kill(alives[0]);
    }
    cout << "! 0" << endl;
  } else {
    while (alives.size() >= 2) {
      int na = alives.size();
      queries.resize(na);
      for (int i = 0; i < na; i++) {
        queries[i] = alives[(i + 1) % na];
      }
      Query();

      bool ok = false;
      for (int i = 0; i < na; i++) {
        if (res[alives[i]] == 1) continue;
        ok = true;
        Kill(alives[(i + 1) % na]);
        break;
      }

      if (!ok) break;
    }
    cout << "! 0" << endl;
  }

  return 0;
}