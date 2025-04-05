// Title : 절댓값 힙
// Link  : https://www.acmicpc.net/problem/11286
// Time  : 12 ms
// Memory: 2412 KB

#include <bits/stdc++.h>

using namespace std;

int heap[100000];
auto hit = heap;

bool Compare(int lhs, int rhs) {
  int a = abs(lhs), b = abs(rhs);
  return a > b || a == b && lhs > rhs;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  while (n--) {
    int x;
    cin >> x;
    if (x) {
      *hit++ = x;
      push_heap(heap, hit, Compare);
    } else {
      if (heap == hit) {
        cout << "0\n";
      } else {
        cout << heap[0] << "\n";
        pop_heap(heap, hit, Compare);
        --hit;
      }
    }
  }

  return 0;
}
