// Title : 바둑이 포커
// Link  : https://www.acmicpc.net/problem/17292 
// Time  : 0 ms
// Memory: 2036 KB

#include <bits/stdc++.h>

using namespace std;

using Card = tuple<int, int, int, int, string>;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<string> strs{""};
  string s;
  cin >> s;
  for (auto c : s) {
    if (c == ',') {
      strs.emplace_back();
    } else {
      strs.back().push_back(c);
    }
  }

  auto GetValue = [](char c) -> int {
    if ('1' <= c && c <= '9') return c - '0';
    return c - 'a' + 10;
  };

  auto GetColor = [](char c) -> int {
    return c == 'b';
  };

  vector<Card> cards;
  for (int i = 0; i < strs.size(); i++) {
    int iv = GetValue(strs[i][0]);
    int ic = GetColor(strs[i][1]);
    for (int j = i + 1; j < strs.size(); j++) {
      int jv = GetValue(strs[j][0]);
      int jc = GetColor(strs[j][1]);
      cards.push_back({iv, ic, jv, jc, strs[i] + strs[j]});
    }
  }

  auto L1 = [](const Card& card) {
    auto [v1, c1, v2, c2, _] = card;
    if (v1 > v2) swap(v1, v2);
    if (v2 - v1 == 1 || v2 - v1 == 14) return 0;
    if (v1 == v2) return 1;
    return 2;
  };

  auto L2 = [](const Card& card) {
    auto [v1, c1, v2, c2, _] = card;
    if (c1 == c2) return 0;
    return 1;
  };

  auto Cmp = [&](const Card& lhs, const Card& rhs) {
    auto ll1 = L1(lhs), rl1 = L1(rhs);
    auto ll2 = L2(lhs), rl2 = L2(rhs);
    if (ll1 != rl1) return ll1 < rl1;
    if (ll2 != rl2) return ll2 < rl2;

    auto [lv1, lc1, lv2, lc2, ls] = lhs;
    auto [rv1, rc1, rv2, rc2, rs] = rhs;
    if (lv1 > lv2) swap(lv1, lv2), swap(lc1, lc2);
    if (rv1 > rv2) swap(rv1, rv2), swap(rc1, rc2);
    if (lv2 != rv2) return lv2 > rv2;
    if (lv1 != rv1) return lv1 > rv1;
    return lc2 > rc2;
  };

  sort(cards.begin(), cards.end(), Cmp);
  for (auto& e : cards) cout << get<4>(e) << "\n";

  return 0;
}
