// Title : 연우의 배수로 뚫기
// Link  : https://www.acmicpc.net/problem/34716 
// Time  : 352 ms
// Memory: 44516 KB

#include <bits/stdc++.h>

using namespace std;

constexpr int kMax = 1 << 18;

vector<int> tree[kMax << 1];
vector<int64_t> cap;

void Update(int l, int r, int64_t v) {
  int nidx = cap.size();
  cap.push_back(v);
  for (l += kMax, r += kMax + 1; l < r; l >>= 1, r >>= 1) {
    if (l & 1) tree[l++].push_back(nidx);
    if (r & 1) tree[--r].push_back(nidx);
  }
}

int64_t Query(int i) {
  int64_t res = 0;
  for (i += kMax; i > 0; i >>= 1) {
    for (auto nidx : tree[i]) {
      res += cap[nidx];
      cap[nidx] = 0;
    }
    tree[i].clear();
  }
  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<int> hrr(n);
  vector<pair<int, int>> arr(n);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    hrr[i] = x;
    arr[i] = {x, i};
  }
  sort(arr.begin(), arr.end(), greater<pair<int, int>>());

  int64_t sum = 0;
  int idx = 0;
  vector<int> stk;
  vector<pair<int, int>> upd;
  set<int> st;
  while (idx < n) {
    int val = arr[idx].first, nxt = idx;
    while (nxt < n && arr[nxt].first == val) {
      auto [h, i] = arr[nxt++];
      stk.push_back(i);
    }

    for (auto i : stk) {
      auto it = st.lower_bound(i);
      if (it != st.begin() && it != st.end()) {
        int rb = *it;
        int lb = *prev(it);
        upd.push_back({lb, rb});
      }
    }
    sort(upd.begin(), upd.end());
    upd.erase(unique(upd.begin(), upd.end()), upd.end());

    while (!upd.empty()) {
      auto [lb, rb] = upd.back();
      upd.pop_back();

      int ph = min<int>(hrr[lb], hrr[rb]);
      int64_t add = (int64_t)(rb - lb - 1) * (ph - val);
      sum += add;
      Update(lb, rb, add);
    }

    while (!stk.empty()) {
      int i = stk.back();
      stk.pop_back();

      st.insert(i);
    }

    idx = nxt;
  }
  cout << sum << "\n";

  int m;
  cin >> m;
  while (m--) {
    int i;
    cin >> i;
    int64_t cut = Query(i - 1);
    sum -= cut;
    cout << sum << "\n";
  }

  return 0;
}