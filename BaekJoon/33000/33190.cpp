// Title : Colorful Intervals
// Link  : https://www.acmicpc.net/problem/33190 
// Time  : 256 ms
// Memory: 62740 KB

#include <bits/stdc++.h>

using namespace std;

struct Node {
  Node() : minn(INT_MAX), nxt{} {}

  int minn;
  int nxt[2];
};

Node nodes[5000001];
int idx;

void Insert(int64_t x, int len) {
  bitset<50> bits(x);
  Node* node = nodes;
  for (int i = 49; i >= 0; i--) {
    int b = bits.test(i);
    if (node->nxt[b] == 0) node->nxt[b] = ++idx;
    node = nodes + node->nxt[b];
    node->minn = min<int>(node->minn, len);
  }
}

int Query(int64_t x, Node* node, int idx) {
  if (x == 0) return node->minn;

  int minn = INT_MAX;
  int64_t b = 1LL << idx;
  if (b & x) {
    x ^= b;
    if (node->nxt[1]) minn = min<int>(minn, Query(x, nodes + node->nxt[1], idx - 1));
  } else {
    if (node->nxt[0]) minn = min<int>(minn, Query(x, nodes + node->nxt[0], idx - 1));
    if (node->nxt[1]) minn = min<int>(minn, Query(x, nodes + node->nxt[1], idx - 1));
  }
  return minn;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  map<string, int> mp;

  auto Get = [&](const string& s) {
    if (auto it = mp.find(s); it != mp.end()) return it->second;
    return mp[s] = mp.size();
  };

  int n;
  cin >> n;
  vector<int> arr(n);
  for (auto& e : arr) {
    string s;
    cin >> s;
    e = Get(s);
  }

  int nc = mp.size(), half = (nc + 1) >> 1, minn = INT_MAX;
  int64_t mask = (1LL << nc) - 1;
  map<int64_t, int> hm;
  for (int i = 0; i < n; i++) {
    bitset<50> bits;
    for (int j = i; j < n; j++) {
      bits.set(arr[j]);
      int len = j - i + 1;
      int64_t cur = bits.to_ullong();
      if (cur == mask) {
        minn = min<int>(minn, len);
        break;
      }
      Insert(cur, len);

      if (bits.count() <= half) {
        if (auto it = hm.find(cur); it != hm.end()) {
          it->second = min<int>(it->second, len);
        } else {
          hm[cur] = len;
        }
      }
    }
  }

  for (auto [x, len] : hm) {
    int add = Query(mask ^ x, nodes, 49);
    if (add == INT_MAX) continue;
    minn = min<int>(minn, len + add);
  }
  cout << minn;

  return 0;
}