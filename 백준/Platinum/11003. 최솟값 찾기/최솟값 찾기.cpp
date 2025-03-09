#include <bits/stdc++.h>

using namespace std;

int memo[5000000];
int heap[5000000];
auto hit = heap;

bool Cmp(int l, int r) {
  return memo[l] > memo[r];
}

void Push(int i, int v) {
  memo[i] = v;
  *hit++ = i;
  push_heap(heap, hit, Cmp);
}

int Top(int limit) {
  while (hit != heap) {
    if (limit <= heap[0]) return memo[heap[0]];
    pop_heap(heap, hit, Cmp);
    --hit;
  }
  return 0;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, l;
  cin >> n >> l;
  --l;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    Push(i, x);
    cout << Top(i - l) << " ";
  }

  return 0;
}
