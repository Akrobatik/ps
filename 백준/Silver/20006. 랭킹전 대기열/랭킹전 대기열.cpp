#include <bits/stdc++.h>

using namespace std;

struct User {
  User(int _lv) : lv(_lv) {}
  int lv;
  char name[17];
};

pair<int, vector<User>> rooms[500];
auto rse = rooms;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int p, m;
  cin >> p >> m;
  while (p--) {
    int lv;
    cin >> lv;
    bool found = false;
    for (auto it = rooms; it != rse; ++it) {
      if (it->second.size() == m || abs(lv - it->first) > 10) continue;
      auto& room = it->second;
      auto& user = room.emplace_back(lv);
      cin >> user.name;
      found = true;
      break;
    }
    if (found) continue;

    rse->first = lv;
    rse->second.reserve(m);
    auto& user = rse->second.emplace_back(lv);
    cin >> user.name;
    ++rse;
  }

  for (auto it = rooms; it != rse; ++it) {
    auto& room = it->second;
    sort(room.begin(), room.end(), [](const User& lhs, const User& rhs) {
      return strcmp(lhs.name, rhs.name) < 0;
    });
    cout << (room.size() == m ? "Started!\n" : "Waiting!\n");
    for (auto& [llv, name] : room) {
      cout << llv << " " << name << "\n";
    }
  }

  return 0;
}
