#include <bits/stdc++.h>

using namespace std;

struct DualPQ {
  void Push(int v) {
    ++mp[v];
  }

  void PopMax() {
    if (mp.empty()) return;
    if (--mp.rbegin()->second == 0) mp.erase(--mp.end());
  }

  void PopMin() {
    if (mp.empty()) return;
    if (--mp.begin()->second == 0) mp.erase(mp.begin());
  }

  void Print() {
    if (mp.empty()) {
      cout << "EMPTY\n";
    } else {
      cout << mp.rbegin()->first << " " << mp.begin()->first << "\n";
    }
  }

  map<int, int> mp;
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    DualPQ dpq;

    int n;
    cin >> n;
    while (n--) {
      char c;
      int v;
      cin >> c >> v;
      if (c == 'I') {
        dpq.Push(v);
      } else {
        if (v == 1) {
          dpq.PopMax();
        } else {
          dpq.PopMin();
        }
      }
    }
    dpq.Print();
  }

  return 0;
}
