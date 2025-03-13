#include <bits/stdc++.h>

using namespace std;

int arr[20000], lcp[20000];
int heap[20000];
auto hend = heap;

void MakeLCP(int n) {
  vector<int> sa(n), p(n), pn(n), cnts(n);

  auto Sort = [&]() {
    fill(cnts.begin(), cnts.end(), 0);
    for (auto e : p) ++cnts[e];
    partial_sum(cnts.begin(), cnts.end(), cnts.begin());
    for (auto e : views::reverse(pn)) sa[--cnts[p[e]]] = e;
  };

  // SA
  for (int i = 0; i < n; i++) sa[i] = pn[i] = i, p[i] = arr[i];
  Sort();
  for (int k = 1; p[sa.back()] + 1 != n; k <<= 1) {
    iota(pn.begin(), pn.begin() + k, n - k);
    for (int i = 0, j = k; i < n; i++) {
      if (sa[i] < k) continue;
      pn[j++] = sa[i] - k;
    }
    Sort();
    int o1, o2;
    o1 = sa[0], pn[o1] = 0;
    for (int i = 1; i < n; i++) {
      o2 = o1, o1 = sa[i];
      pn[o1] = pn[o2];
      if (o1 + k < n && o2 + k < n && p[o1] == p[o2] && p[o1 + k] == p[o2 + k]) continue;
      ++pn[o1];
    }
    swap(p, pn);
  }

  // LCP
  for (int i = 0, k = 0; i < n; i++, k && --k) {
    if (p[i] == 0) continue;
    int j = sa[p[i] - 1];
    while (i + k < n && j + k < n && arr[i + k] == arr[j + k]) ++k;
    lcp[p[i]] = k;
  }
}

void Compress(int n) {
  vector<int> orders(arr, arr + n);
  auto b = orders.begin(), e = orders.end();
  sort(b, e);
  e = unique(orders.begin(), orders.end());
  for (int i = 0; i < n; i++) {
    arr[i] = lower_bound(b, e, arr[i]) - b;
  }
}

bool Cmp(int i, int j) {
  return lcp[i] > lcp[j];
}

void Push(int i) {
  *hend++ = i;
  push_heap(heap, hend, Cmp);
}

int Top(int limit) {
  while (heap[0] <= limit) pop_heap(heap, hend--, Cmp);
  return lcp[heap[0]];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> arr[i];
  Compress(n);
  MakeLCP(n);

  for (int i = 0; i < k - 1; i++) {
    Push(i);
  }
  int ans = Top(-1);
  for (int i = k - 1, j = 0; i < n; i++, j++) {
    Push(i);
    ans = max<int>(ans, Top(j));
  }
  cout << ans;

  return 0;
}
