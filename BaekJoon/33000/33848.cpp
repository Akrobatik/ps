// Title : 퍼시스턴트 스택
// Link  : https://www.acmicpc.net/problem/33848 
// Time  : 36 ms
// Memory: 6812 KB

#include <bits/stdc++.h>

using namespace std;

struct Node {
  Node() : Node(0, 0, nullptr) {}
  Node(int _x, int _sz, Node* _p) : x(_x), sz(_sz), p(_p) {}

  int x, sz;
  Node* p;
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int q;
  cin >> q;

  int cur = 0, idx = 0;
  vector<Node> nodes(q + 1);
  vector<int> rollback;
  while (q--) {
    int cmd;
    cin >> cmd;
    switch (cmd) {
      case 1: {
        int x;
        cin >> x;
        auto& node = nodes[++idx];
        node.x = x;
        node.sz = nodes[cur].sz + 1;
        node.p = nodes.data() + cur;
        rollback.push_back(idx);
        cur = idx;
      } break;

      case 2: {
        Node* old = nodes.data() + cur;
        Node* prv = old->p;
    
        auto& node = nodes[++idx];
        if (prv) {
          node.x  = prv->x;
          node.p  = prv->p;
        }
        node.sz = nodes[cur].sz - 1;
        rollback.push_back(idx);
        cur = idx;
      } break;

      case 3: {
        int x;
        cin >> x;
        rollback.resize(rollback.size() - x);
        cur = rollback.empty() ? 0 : rollback.back();
      } break;

      case 4: {
        cout << nodes[cur].sz << "\n";
      } break;

      case 5: {
        auto& node = nodes[cur];
        cout << (node.sz ? node.x : -1) << "\n";
      } break;
    }
  }

  return 0;
}
