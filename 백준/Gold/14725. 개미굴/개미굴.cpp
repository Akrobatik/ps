#include <bits/stdc++.h>

using namespace std;

struct Tree {
  void Insert(const vector<string>& vec) {
    auto mm = &m;
    for (auto& s : vec) {
      if (!mm->contains(s)) {
        mm->insert({s, Tree()});
      }
      mm = &(*mm)[s].m;
    }
  }

  void Print(int depth) {
    string prefix(depth << 1, '-');
    for (auto& [k, v] : m) {
      cout << prefix << k << "\n";
      v.Print(depth + 1);
    }
  }

  map<string, Tree> m;
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  Tree tree;
  vector<string> vec;
  for (int i = 0; i < n; i++) {
    int nn;
    cin >> nn;
    vec.resize(nn);
    for (int j = 0; j < nn; j++) cin >> vec[j];
    tree.Insert(vec);
  }
  tree.Print(0);

  return 0;
}
