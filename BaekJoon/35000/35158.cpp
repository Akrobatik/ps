// Title : 점 세게 돌리기
// Link  : https://www.acmicpc.net/problem/35158 
// Time  : 1488 ms
// Memory: 31092 KB

#include <bits/stdc++.h>

using namespace std;

int table[48][48];
int64_t memo[6][6][1 << 8][1 << 8];

// https://github.com/Akrobatik/ps/blob/main/template/segment_tree.cpp
template <typename V, typename OP>
  requires requires(V a, V b) {
    { OP{}(a, b) } -> convertible_to<V>;
  }
struct SegTree {
  void Init(int n, const V& ival) {
    nmax = bit_ceil((uint32_t)n);
    iv = ival;
    tree.assign(nmax << 1, iv);
  }

  void Set(int idx, const V& val) {
    tree[idx + nmax] = val;
  }

  void Build() {
    for (int i = nmax - 1; i > 0; i--) {
      tree[i] = OP{}(tree[i << 1], tree[i << 1 | 1]);
    }
  }

  void Update(int idx, const V& val) {
    int node = idx + nmax;
    tree[node] = val;
    while (node >>= 1) {
      tree[node] = OP{}(tree[node << 1], tree[node << 1 | 1]);
    }
  }

  V Query(int idx) const {
    return tree[idx + nmax];
  }

  V Query(int l, int r) const {
    V lv = iv, rv = iv;
    for (l += nmax, r += nmax + 1; l < r; l >>= 1, r >>= 1) {
      if (l & 1) lv = OP{}(lv, tree[l++]);
      if (r & 1) rv = OP{}(tree[--r], rv);
    }
    return OP{}(lv, rv);
  }

 private:
  int nmax;
  V iv;
  vector<V> tree;
};

int64_t Bridge(char c) {
  if (c == 'X') {
    return 1LL << 9;
  } else if (c == 'Y') {
    return 1LL << 44;
  } else {
    return 1LL << 18;
  }
}

int64_t Bridge(char lc, char rc) {
  if (lc == rc) {
    if (lc == 'X') {
      return 1LL << 3;
    } else if (lc == 'Y') {
      return 1LL << 5;
    } else {
      return 1LL << 6;
    }
  } else {
    char c = lc ^ rc ^ 91;
    if (c == 'X') {
      return 1LL << 4;
    } else if (c == 'Y') {
      return 1LL << 2;
    } else {
      return 1LL << 1;
    }
  }
}

int64_t Comp(int64_t lv, int64_t rv) {
  int64_t res = 0;
  for (int i = 0; i < 6; i++) {
    for (int j = 0; j < 6; j++) {
      res |= memo[i][j][(lv >> (i * 8)) & 255][(rv >> (j * 8)) & 255];
    }
  }
  return res;
}

struct Node {
  Node() : len(0), lc(0), rc(0), fwd(0), bwd(0), mid(0), all(0) {}
  Node(char c) : len(1), lc(c), rc(c), fwd(1), bwd(1), mid(1), all(Bridge(c)) {}

  int len;
  char lc, rc;
  int64_t fwd, bwd, mid, all;
};

struct FOp {
  Node operator()(const Node& a, const Node& b) const {
    if (a.len == 0) return b;
    if (b.len == 0) return a;

    int64_t br = Bridge(a.rc, b.lc);

    Node res;
    res.len = a.len + b.len;
    res.lc = a.lc;
    res.rc = b.rc;
    if (a.len == 1 && b.len == 1) {
      res.fwd = a.all;
      res.bwd = b.all;
      res.mid = 1;
      res.all = Comp(a.all, b.all) | Bridge(a.lc, b.rc);
    } else if (a.len == 1) {
      res.fwd = Comp(a.all, b.fwd) | Comp(br, b.mid);
      res.bwd = b.all;
      res.mid = b.fwd;
      res.all = Comp(a.all, b.all) | Comp(br, b.bwd);
    } else if (b.len == 1) {
      res.fwd = a.all;
      res.bwd = Comp(a.bwd, b.all) | Comp(a.mid, br);
      res.mid = a.bwd;
      res.all = Comp(a.all, b.all) | Comp(a.fwd, br);
    } else {
      res.fwd = Comp(a.all, b.fwd) | Comp(Comp(a.fwd, br), b.mid);
      res.bwd = Comp(a.bwd, b.all) | Comp(Comp(a.mid, br), b.bwd);
      res.mid = Comp(a.bwd, b.fwd) | Comp(Comp(a.mid, br), b.mid);
      res.all = Comp(a.all, b.all) | Comp(Comp(a.fwd, br), b.bwd);
    }
    return res;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  array<int, 3> arr{0, 1, 2};

  vector<array<int, 6>> axr;
  do {
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < 2; j++) {
        for (int k = 0; k < 2; k++) {
          axr.push_back({arr[0], arr[1], arr[2], i, j, k});
        }
      }
    }
  } while (next_permutation(arr.begin(), arr.end()));

  map<array<int, 6>, int> mp;
  for (int i = 0; i < 48; i++) {
    mp[axr[i]] = i;
  }

  for (int i = 0; i < 48; i++) {
    auto& a = axr[i];
    for (int j = 0; j < 48; j++) {
      auto& b = axr[j];

      array<int, 6> tmp;
      for (int k = 0; k < 3; k++) {
        int apos = a[k], asign = a[k + 3];
        int bpos = b[apos], bsign = b[apos + 3];
        tmp[k] = bpos, tmp[k + 3] = asign ^ bsign;
      }

      table[i][j] = mp[tmp];
    }
  }

  for (int i = 0; i < 6; i++) {
    for (int j = 0; j < 6; j++) {
      for (int k = 0; k < 256; k++) {
        for (int l = 0; l < 256; l++) {
          int64_t val = 0;
          for (int a = 0; a < 8; a++) {
            if (!((k >> a) & 1)) continue;
            for (int b = 0; b < 8; b++) {
              if (!((l >> b) & 1)) continue;
              val |= 1LL << table[a + (i << 3)][b + (j << 3)];
            }
          }
          memo[i][j][k][l] = val;
        }
      }
    }
  }

  int x, y, z;
  string s;
  cin >> x >> y >> z >> s;
  int n = s.size();

  SegTree<Node, FOp> seg;
  seg.Init(n + 1, Node());
  for (int i = 0; i < n; i++) {
    seg.Set(i + 1, Node(s[i]));
  }
  seg.Build();

  vector<array<int, 3>> tmp;

  int q;
  cin >> q;
  while (q--) {
    int l, r;
    cin >> l >> r;

    int64_t val = seg.Query(l, r).all;
    tmp.clear();
    for (int i = 0; i < 48; i++) {
      if ((val >> i) & 1) {
        array<int, 3> t;
        t[axr[i][0]] = x * (axr[i][3] ? -1 : 1);
        t[axr[i][1]] = y * (axr[i][4] ? -1 : 1);
        t[axr[i][2]] = z * (axr[i][5] ? -1 : 1);
        tmp.push_back(t);
      }
    }
    sort(tmp.begin(), tmp.end());
    tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
    cout << tmp.size() << "\n";
  }

  return 0;
}