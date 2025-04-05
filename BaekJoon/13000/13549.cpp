// Title : 숨바꼭질 3
// Link  : https://www.acmicpc.net/problem/13549
// Time  : 4 ms
// Memory: 2728 KB

#include <bits/stdc++.h>

using namespace std;

int x, y;
bool memo[200001];

struct Elem : public pair<int, int> {
  Elem(int pos, int sec) : pair<int, int>(make_pair(pos, sec)) {}

  constexpr auto operator<=>(const Elem& rhs) const {
    return second <=> rhs.second;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> x >> y;

  priority_queue<Elem, vector<Elem>, greater<Elem>> pq;
  pq.push(Elem(x, 0));
  while (!pq.empty()) {
    auto [pos, sec] = pq.top();
    pq.pop();

    if (pos == y) {
      cout << sec << endl;
      break;
    }

    memo[pos] = true;
    if (pos < y) {
      if (!memo[pos * 2]) pq.push(Elem(pos * 2, sec));
      if (!memo[pos + 1]) pq.push(Elem(pos + 1, sec + 1));
    }
    if (pos > 0 && !memo[pos - 1]) pq.push(Elem(pos - 1, sec + 1));
  }

  return 0;
}
