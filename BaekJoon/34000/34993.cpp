// Title : 볼록 껍질과 쿼리
// Link  : https://www.acmicpc.net/problem/34993 
// Time  : 4 ms
// Memory: 30360 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  int q = (n + 1) >> 1;
  vector<array<int, 3>> qr(q);
  for (int i = 0; i < q; i++) {
    int a = i * 2 + 1, b = a + 1, c = a + 2;
    if (b > n) b -= n;
    if (c > n) c -= n;
    if (b == 1 && c == 2) c = 5;
    qr[i] = {a, b, c};
    sort(qr[i].begin(), qr[i].end());
  }

  vector<array<pair<int, int>, 3>> arr(q);
  for (int i = 0; i < q; i++) {
    cout << "? 3 " << qr[i][0] << " " << qr[i][1] << " " << qr[i][2] << endl;

    int cnt;
    cin >> cnt;
    for (auto& [x, y] : arr[i]) cin >> x >> y;
    sort(arr[i].begin(), arr[i].end());
  }

  vector<int8_t> done(n + 1);
  vector<pair<int, int>> coords(n + 1);
  for (int i = 0; i < q; i++) {
    auto& qa = qr[i];
    auto& qb = qr[(i + 1) % q];
    int qi;
    for (auto e : qa) {
      if (binary_search(qb.begin(), qb.end(), e)) {
        qi = e;
        break;
      }
    }

    auto& aa = arr[i];
    auto& ab = arr[(i + 1) % q];
    pair<int, int> axy;
    for (auto e : aa) {
      if (binary_search(ab.begin(), ab.end(), e)) {
        axy = e;
        break;
      }
    }

    done[qi] = 1;
    coords[qi] = axy;
  }

  while (*min_element(done.begin() + 1, done.end()) == 0) {
    for (int i = 0; i < q; i++) {
      int cnt = 0, idx = 0;
      pair<int, int> xy{};
      for (auto [x, y] : arr[i]) xy.first ^= x, xy.second ^= y;
      for (auto e : qr[i]) {
        idx ^= e;
        if (done[e]) {
          idx ^= e, ++cnt;
          xy.first ^= coords[e].first;
          xy.second ^= coords[e].second;
        }
      }

      if (cnt == 2) {
        done[idx] = 1;
        coords[idx] = xy;
      }
    }
  }

  cout << "!";
  for (int i = 1; i <= n; i++) {
    auto [x, y] = coords[i];
    cout << " " << x << " " << y;
  }
  cout << endl;

  return 0;
}