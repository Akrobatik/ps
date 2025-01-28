#include <bits/stdc++.h>

using namespace std;

struct Node {
  Node() : left(nullptr), right(nullptr), idx(0), team_id(0) {}

  Node *left, *right;
  int idx, team_id;
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> votes;
    votes.resize(n + 1);
    for (int i = 1; i <= n; i++) cin >> votes[i];

    vector<Node> _nodes(n + 1, Node());
    auto nodes = _nodes.data();

    int sum = 0;
    for (int i = 1; i <= n; i++) {
      auto cur = nodes + i;
      if (cur->right) continue;

      int cnt = 0;
      while (cur->right == nullptr) {
        int id = cur - nodes;
        auto next = nodes + votes[id];
        cur->idx = cnt++;
        cur->team_id = i;
        cur->right = next;
        next->left = cur;
        cur = next;
      }

      if (cur->team_id == i) sum += cnt - cur->idx;
    }

    cout << n - sum << "\n";
  }

  return 0;
}
