#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int64_t sum = 0;
    map<int, int> memo[5];

    int n;
    cin >> n;
    while (n--) {
      int a;
      cin >> a;
      queue<pair<int, int>> q;
      q.push({a, a});

      // cerr << "Push: " << a << "\n";
      for (int i = 0; !q.empty() && i < 5; i++) {
        int nq = q.size();
        while (nq--) {
          auto [v, r] = q.front();
          q.pop();

          int rem = r;
          auto it = memo[i].upper_bound(v);
          while (rem && it != memo[i].end()) {
            int cut = min<int>(rem, it->second);
            sum -= cut;
            rem -= cut;
            q.push({it->first, cut});
            if ((it->second -= cut) == 0) it = memo[i].erase(it);
            // cerr << "Sub: " << i << " " << cut << "\n";
          }

          memo[i][v] += r;
          sum += r;
          // cerr << "Add: " << i << " " << rem << "\n";
        }
      }

      cout << sum << " ";
    }
    cout << "\n";
  }

  return 0;
}
