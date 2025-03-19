#include <bits/stdc++.h>

using namespace std;

constexpr int kMax = 500000;
constexpr int64_t kMod = 1e9 + 9;
constexpr int64_t kBase = 131;

int64_t h[kMax + 1], p[kMax + 1];
int memo[kMax + 1];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  p[0] = 1;
  for (int i = 0; i < kMax; i++) {
    p[i + 1] = (p[i] * kBase) % kMod;
  }

  string s1, s2;

  int t;
  cin >> t;
  while (t--) {
    unordered_set<int64_t> st;
    stack<int> stk1, stk2;

    cin >> s1 >> s2;
    int n1 = s1.size(), n2 = s2.size();

    for (int i = 0; i < n1; i++) {
      h[i + 1] = (h[i] + s1[i] * p[i]) % kMod;
    }

    memset(memo, 0, (n1 + 1) * sizeof(int));
    for (int i = 0; i < n1; i++) {
      if (s1[i] == '(') {
        stk1.push(i);
      } else if (!stk1.empty()) {
        auto b = stk1.top(), e = i + 1;
        int64_t len = e - b;
        stk1.pop();

        int64_t x = (len << 32) | ((h[e] - h[b] + kMod) % kMod * p[kMax - b] % kMod);
        st.insert(x);

        int bb = memo[b];
        while (bb) {
          x = ((len + b - bb + 1) << 32) | ((h[e] - h[bb - 1] + kMod) % kMod * p[kMax - bb + 1] % kMod);
          st.insert(x);
          bb = memo[bb - 1];
        }

        memo[e] = b + 1;
      }
    }

    for (int i = 0; i < n2; i++) {
      h[i + 1] = (h[i] + s2[i] * p[i]) % kMod;
    }

    int ans = 0;

    memset(memo, 0, (n2 + 1) * sizeof(int));
    for (int i = 0; i < n2; i++) {
      if (s2[i] == '(') {
        stk2.push(i);
      } else if (!stk2.empty()) {
        auto b = stk2.top(), e = i + 1;
        int64_t len = e - b;
        stk2.pop();

        int64_t x = (len << 32) | ((h[e] - h[b] + kMod) % kMod * p[kMax - b] % kMod);
        if (st.contains(x)) {
          ans = max<int>(ans, len);
        }

        int bb = memo[b];
        while (bb) {
          x = ((len + b - bb + 1) << 32) | ((h[e] - h[bb - 1] + kMod) % kMod * p[kMax - bb + 1] % kMod);
          if (st.contains(x)) {
            ans = max<int>(ans, len + b - bb + 1);
          }
          bb = memo[bb - 1];
        }

        memo[e] = b + 1;
      }
    }

    cout << ans << "\n";
  }

  return 0;
}
