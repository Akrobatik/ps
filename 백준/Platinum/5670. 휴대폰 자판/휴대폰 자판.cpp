#include <bits/stdc++.h>

using namespace std;

struct Node {
  bool exist;
  map<char, Node> nxt;
};

int idx;
char s[100000][81];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cout.precision(2);

  int n;
  while (cin >> n) {
    Node root;
    for (int i = 0; i < n; i++) {
      cin >> s[i];
      Node* node = &root;
      for (auto ptr = s[i]; *ptr; ++ptr) {
        node = &node->nxt[*ptr];
      }
      node->exist = true;
    }

    int sum = 0;
    for (int i = 0; i < n; i++) {
      ++sum;
      auto ptr = s[i];
      Node* node = &root.nxt[*ptr++];
      while (*ptr) {
        sum += (node->nxt.size() != 1 || node->exist);
        node = &node->nxt[*ptr++];
      }
    }

    int mid = (n + (n & 1)) >> 1;
    sum *= 100;
    sum = sum / n + (sum % n >= mid);
    cout << fixed << (double)sum / 100.0 << "\n";
  }

  return 0;
}
