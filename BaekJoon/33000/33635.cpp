// Title : ─점심시간─
// Link  : https://www.acmicpc.net/problem/33635
// Time  : 540 ms
// Memory: 2320 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  unordered_map<string, int> genres;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    genres[s] = i;
  }

  int m;
  cin >> m;
  vector<bitset<200>> books(m);
  while (m--) {
    int k;
    string s;
    cin >> k >> s;
    while (k--) {
      cin >> s;
      books[m].set(genres[s]);
    }
  }

  int q;
  cin >> q;
  while (q--) {
    int x;
    string s;
    cin >> x;
    bitset<200> bits;
    while (x--) {
      cin >> s;
      bits.set(genres[s]);
    }

    int cnt = 0;
    for (auto& b : books) {
      cnt += ((b & bits) == bits);
    }
    cout << cnt << "\n";
  }

  return 0;
}
