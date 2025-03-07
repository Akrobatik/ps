#include <bits/stdc++.h>

using namespace std;

struct Node {
  bool exist;
  map<char, Node> nxt;
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  char s[2001];
  Node croot;
  int c, n;
  cin >> c >> n;
  while (c--) {
    cin >> s;
    Node* node = &croot;
    for (auto ptr = s; *ptr; ++ptr) {
      node = &node->nxt[*ptr];
    }
    node->exist = true;
  }

  unordered_set<string> hs;
  while (n--) {
    cin >> s;
    hs.insert(s);
  }

  int q;
  cin >> q;
  Node* root = &croot;
  while (q--) {
    cin >> s;
    string_view sv(s);
    auto node = root;
    bool found = false;
    for (int i = 0; i < sv.size() - 1; i++) {
      auto it = node->nxt.find(sv[i]);
      if (it == node->nxt.end()) break;
      if (it->second.exist && hs.contains(string(sv.substr(i + 1)))) {
        found = true;
        break;
      }
      node = &it->second;
    }
    cout << (found ? "Yes\n" : "No\n");
  }

  return 0;
}
