// Title : 트리의 지름
// Link  : https://www.acmicpc.net/problem/1167
// Time  : 80 ms
// Memory: 20440 KB

#include <bits/stdc++.h>

using namespace std;

using Node = vector<pair<int, int>>;

Node nodes[100001];
int memo[100001];
bool visited[100001];

int Traverse(Node* node, int len) {
  int cur_id = distance(nodes, node);
  if (visited[cur_id]) return 0;
  visited[cur_id] = true;

  int n = node->size();
  if (n == 0) {
    return len;
  } else if (n == 1) {
    auto [id, cost] = node->front();
    return len + Traverse(nodes + id, cost);
  } else {
    vector<int> lens(n, 0);
    for (int i = 0; i < n; i++) {
      auto [id, cost] = node->at(i);
      lens[i] = Traverse(nodes + id, cost);
    }
    sort(lens.begin(), lens.end(), greater<int>());
    memo[distance(nodes, node)] = lens[0] + lens[1];
    return len + lens[0];
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    for (;;) {
      int b, c;
      cin >> b;
      if (b == -1) break;
      cin >> c;
      nodes[a].push_back({b, c});
    }
  }

  int unary = Traverse(nodes + 1, 0);
  int binary = *max_element(memo + 1, memo + n + 1);
  cout << max<int>(unary, binary) << endl;

  return 0;
}
