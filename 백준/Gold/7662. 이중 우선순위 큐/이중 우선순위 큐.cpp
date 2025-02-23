#include <bits/stdc++.h>

using namespace std;

template <typename Pred>
struct PQ {
  void Push(int v) { pq.push(v); }
  void Erase(int v) { eq.push(v); }
  bool Pop(int& out) {
    while (!pq.empty() && !eq.empty() && pq.top() == eq.top()) pq.pop(), eq.pop();
    if (pq.empty()) return false;
    out = pq.top();
    pq.pop();
    return true;
  }

  priority_queue<int, vector<int>, Pred> pq, eq;
};

struct DualPQ {
  void Push(int v) {
    maxq.Push(v);
    minq.Push(v);
  }

  bool PopMax(int& out) {
    if (!maxq.Pop(out)) return false;
    minq.Erase(out);
    return true;
  }

  bool PopMin(int& out) {
    if (!minq.Pop(out)) return false;
    maxq.Erase(out);
    return true;
  }

  PQ<less<int>> maxq;
  PQ<greater<int>> minq;
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    DualPQ dpq;
    int n;
    cin >> n;
    while (n--) {
      char op;
      int v;
      cin >> op >> v;
      if (op == 'I') {
        dpq.Push(v);
      } else {
        if (v == 1) {
          dpq.PopMax(v);
        } else {
          dpq.PopMin(v);
        }
      }
    }
    int maxx, minn;
    if (!dpq.PopMax(maxx)) {
      cout << "EMPTY\n";
    } else {
      if (!dpq.PopMin(minn)) minn = maxx;
      cout << maxx << " " << minn << "\n";
    }
  }

  return 0;
}
