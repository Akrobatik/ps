// Title : 다항 함수의 적분
// Link  : https://www.acmicpc.net/problem/17214 
// Time  : 0 ms
// Memory: 2112 KB

#include <bits/stdc++.h>

using namespace std;

optional<pair<int, string>> Parse(string_view sv) {
  if (sv.empty()) return nullopt;

  int sign = 1;
  int idx = 0;
  if (sv[idx] == '-') {
    sign = -1, ++idx;
  } else if (sv[idx] == '+') {
    ++idx;
  }

  int num = 0;
  while (idx < sv.size() && '0' <= sv[idx] && sv[idx] <= '9') num = num * 10 + sv[idx++] - '0';
  if (num == 0) return nullopt;

  int order = 0;
  while (idx < sv.size() && sv[idx] == 'x') ++order, ++idx;
  num /= order + 1;

  ostringstream oss;
  if (sign == -1) oss << '-';
  if (num != 1) oss << num;
  for (int i = 0; i <= order; i++) oss << 'x';
  return make_pair(order, oss.str());
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string expr;
  cin >> expr;

  vector<pair<int, string>> terms;
  string_view sv = expr;
  while (!sv.empty()) {
    int e = 1;
    while (e < sv.size() && sv[e] != '+' && sv[e] != '-') ++e;
    auto res = Parse(sv.substr(0, e));
    if (res.has_value()) terms.push_back(res.value());
    sv = sv.substr(e);
  }
  sort(terms.begin(), terms.end(), greater<>());

  if (terms.empty()) {
    cout << "W";
    return 0;
  }

  ostringstream oss;
  for (int i = 0; i < terms.size(); i++) {
    auto& s = terms[i].second;
    if (i && s[0] != '-') oss << '+';
    oss << s;
  }
  oss << "+W";
  cout << oss.str();

  return 0;
}
