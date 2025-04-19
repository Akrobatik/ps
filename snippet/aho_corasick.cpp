#include <bits/stdc++.h>

using namespace std;

struct AhoCorasick {
 private:
  struct Node {
    Node() : nxt{}, pass(0), fail(0) {}

    array<int, 26> nxt;
    int pass, fail;
  };

 public:
  AhoCorasick() : nodes(2), memo(2) {}

  void AddString(const string& s) {
    int u = 1;
    for (auto c : s) {
      c -= 'a';
      if (nodes[u].nxt[c] == 0) nodes[u].nxt[c] = AddNode();
      u = nodes[u].nxt[c];
    }
    ++nodes[u].pass;
  }

  void Build() {
    queue<int> q;
    nodes[1].fail = 1;
    q.push(1);
    while (!q.empty()) {
      int u = q.front();
      q.pop();

      for (int i = 0; i < 26; i++) {
        int v = nodes[u].nxt[i];
        if (v == 0) continue;

        nodes[v].fail = (u == 1 ? 1 : Find(nodes[u].fail, i));
        nodes[v].pass += nodes[nodes[v].fail].pass;
        q.push(v);
      }
    }
  }

  bool Find(const string& s) {
    int u = 1;
    for (int i = 0; i < s.size(); i++) {
      u = Find(u, s[i] - 'a');
      if (nodes[u].pass) return true;
    }
    return false;
  }

 private:
  vector<Node> nodes;
  vector<array<int, 26>> memo;

  int AddNode() {
    int res = nodes.size();
    nodes.emplace_back();
    memo.emplace_back();
    return res;
  }

  int Find(int u, int i) {
    if (memo[u][i]) return memo[u][i];

    int res;
    auto& node = nodes[u];
    if (u != 1 && node.nxt[i] == 0) {
      res = Find(node.fail, i);
    } else if (node.nxt[i]) {
      res = node.nxt[i];
    } else {
      res = 1;
    }
    return memo[u][i] = res;
  }
};