// Title : BNKQ
// Link  : https://www.acmicpc.net/problem/18386 
// Time  : 0 ms
// Memory: 2100 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  unordered_set<string> hs;
  unordered_map<string, array<int, 8>> hm;

  auto GetTime = [&](const string& s) {
    int ns = s.size();
    int hh = stoi(s.substr(0, 2));
    return s[ns - 2] == 'A' ? hh - 8 : hh + 4;
  };

  auto ToTime = [&](int idx) {
    ostringstream oss;
    oss << setw(2) << setfill('0') << (idx <= 4 ? idx + 8 : idx - 4) << (idx <= 3 ? "AM" : "PM");
    return oss.str();
  };

  string line;
  while (getline(cin, line) && line != "ENDOFINPUT") {
    istringstream iss(line);
    string teller, customer, time;
    iss >> teller >> customer >> time;
    if (time.empty()) continue;

    if (hs.contains(customer)) {
      hs.erase(customer);
      hm[teller][GetTime(time)] += 1;
    } else {
      hs.insert(customer);
    }
  }

  vector<pair<int, string>> memo;
  for (auto& [k, v] : hm) {
    int sum = accumulate(v.begin(), v.end(), 0);
    memo.push_back({sum, k});
    sort(memo.begin(), memo.end(), [&](const pair<int, string>& lhs, const pair<int, string>& rhs) {
      auto& [ls, ln] = lhs;
      auto& [rs, rn] = rhs;
      return ls > rs || (ls == rs && ln < rn);
    });
    while (memo.size() > 3) memo.pop_back();
  }

  for (auto& [sum, name] : memo) {
    int pv = -1, pi;
    auto& arr = hm[name];
    for (int i = 0; i < 8; i++) {
      if (pv < arr[i]) pv = arr[i], pi = i;
    }
    cout << name << " " << sum << " " << ToTime(pi) << "\n";
  }

  return 0;
}