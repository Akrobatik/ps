// Title : 팰린드롬
// Link  : https://www.acmicpc.net/problem/10066
// Time  : 156 ms
// Memory: 52520 KB

#include <bits/stdc++.h>

using namespace std;

struct Manacher {
  void Init(string_view sv) {
    int n = (sv.size() << 1) + 1;
    table.clear(), table.resize(n);

    string s(n, '\0');
    auto ptr = s.data() + 1;
    for (char c : sv) *ptr = c, ptr += 2;

    int p, r = 0;
    for (int i = 1; i < n - 1; i++) {
      if (i > r) {
        p = r = i;
        while (r < n && r <= (p << 1) && s[r] == s[(p << 1) - r]) ++r;
        table[i] = --r - p;
      } else {
        if (table[(p << 1) - i] < r - i) {
          table[i] = table[(p << 1) - i];
        } else if (table[(p << 1) - i] > r - i) {
          table[i] = r - i;
        } else {
          p = i;
          while (r < n && r <= (p << 1) && s[r] == s[(p << 1) - r]) ++r;
          table[i] = --r - p;
        }
      }
    }
  }

  vector<int> table;
};

struct Node {
  int len, cnt;
  vector<int> parents;
};

constexpr int64_t kMod = 1e9 + 9;
constexpr int64_t kBase = 131;

char s[300001];
int64_t h[300001], p[300001];
int nidx;
Node nodes[300001];
int cnts[300001];
unordered_map<int64_t, int> hm;
bool bchild[300002], visited[300002];

void Add(int pos, int len, int max_len, int par, int first = 1) {
  if (len <= 0) return;

  int cur;
  int64_t x = ((int64_t)len << 32) | (((h[pos + len] - h[pos] + kMod) % kMod) * p[max_len - pos] % kMod);
  if (auto it = hm.find(x); it != hm.end()) {
    cur = it->second;
    nodes[cur].cnt += first;
  } else {
    hm[x] = cur = ++nidx;
    auto node = nodes + nidx;
    node->cnt = first, node->len = len;
    Add(pos + 1, len - 2, max_len, cur, 0);
  }

  if (par && !bchild[par]) {
    bchild[par] = true;
    nodes[cur].parents.push_back(par);
  }
}

void Traverse(int cur) {
  visited[cur] = true;
  cnts[cur] = nodes[cur].cnt;
  for (auto nxt : nodes[cur].parents) {
    if (!visited[nxt]) Traverse(nxt);
    cnts[cur] += cnts[nxt];
  }
}

int main() {
  string s;
  cin >> s;
  int n = s.size();

  p[0] = 1;
  for (int i = 0; i < n; i++) {
    h[i + 1] = (h[i] + s[i] * p[i]) % kMod;
    p[i + 1] = p[i] * kBase % kMod;
  }

  Manacher manacher;
  manacher.Init(s);

  auto& mtable = manacher.table;
  int nm = manacher.table.size();
  for (int i = 0; i < nm; i++) {
    if (mtable[i] == 0) continue;
    Add((i - mtable[i]) >> 1, mtable[i], n, 0);
  }

  for (int i = 1; i <= nidx; i++) {
    if (visited[i]) continue;
    Traverse(i);
  }

  int64_t ans = 0;
  for (int i = 1; i <= nidx; i++) {
    ans = max<int64_t>(ans, (int64_t)cnts[i] * nodes[i].len);
  }
  cout << ans;

  return 0;
}
