// Title : 불의 군주 라그나로스 1
// Link  : https://www.acmicpc.net/problem/33685 
// Time  : 2612 ms
// Memory: 56656 KB

#include <bits/stdc++.h>

using namespace std;

constexpr int64_t kMod = 998244353;
constexpr int64_t kMod1 = 1e9 + 9;
constexpr int64_t kBase1 = 127;
constexpr int64_t kMod2 = 1e9 + 7;
constexpr int64_t kBase2 = 131;

int64_t pw1[20], pw2[20];

struct State {
  State() : hp(0), rem(0), h(0), mob{} {}

  int hp, rem;
  int64_t h;
  array<int8_t, 20> mob;

  void CalcHash(int n) {
    int64_t h1 = (int64_t)hp + (int64_t)rem * kBase1;
    int64_t h2 = (int64_t)hp + (int64_t)rem * kBase2;
    for (int i = 0; i < n; i++) {
      h1 += pw1[i] * mob[i];
      h2 += pw2[i] * mob[i];
    }
    h1 %= kMod1, h2 %= kMod2;
    h = (h1 << 32) | h2;
  }

  bool operator==(const State& other) const {
    return h == other.h;
  }
};

template <>
struct std::hash<State> {
  int64_t operator()(const State& state) const {
    return state.h;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int64_t p1 = kBase1 * kBase1;
  int64_t p2 = kBase2 * kBase2;
  for (int i = 0; i < 20; i++) {
    pw1[i] = p1, pw2[i] = p2;
    p1 = p1 * kBase1 % kMod1;
    p2 = p2 * kBase2 % kMod2;
  }

  int64_t inv[122] = {0, 1};
  for (int i = 2; i < 122; i++) {
    inv[i] = (kMod - kMod / i) * inv[kMod % i] % kMod;
  }

  int n, m, x, y;
  cin >> n >> m >> x >> y;

  State init;
  init.hp = (y + x - 1) / x;
  init.rem = m;
  for (int i = 0; i < m; i++) {
    int v;
    cin >> v;
    v = (v + x - 1) / x;
    if (v < n) ++init.mob[v];
  }
  init.CalcHash(n);

  int64_t ans = 0;
  unordered_map<State, int64_t> memo;
  memo[init] = 1;
  for (int i = 0; i < n; i++) {
    unordered_map<State, int64_t> mnxt;
    for (auto& [state, prob] : memo) {
      if (state.hp == 0) ans = (ans + prob) % kMod;
      if (state.hp == 0 || state.hp - n + i > 0) continue;

      int rem = state.rem;
      const int64_t np = prob * inv[state.rem + 1] % kMod;
      for (int j = 1; j < n - i; j++) {
        int cnt = state.mob[j];
        if (cnt == 0) continue;
        rem -= cnt;
        auto nxt = state;
        --nxt.mob[j];
        if (j == 1) {
          --nxt.rem;
        } else {
          ++nxt.mob[j - 1];
        }
        nxt.CalcHash(n - i - 1);
        mnxt[nxt] = (mnxt[nxt] + np * cnt) % kMod;
      }

      if (rem) {
        auto nxt = state;
        nxt.CalcHash(n - i - 1);
        mnxt[nxt] = (mnxt[nxt] + np * rem) % kMod;
      }

      auto nxt = state;
      --nxt.hp;
      nxt.CalcHash(n - i - 1);
      mnxt[nxt] = (mnxt[nxt] + np) % kMod;
    }
    memo.swap(mnxt);
  }

  for (auto& [state, prob] : memo) {
    if (state.hp == 0) ans = (ans + prob) % kMod;
  }
  cout << ans;

  return 0;
}
