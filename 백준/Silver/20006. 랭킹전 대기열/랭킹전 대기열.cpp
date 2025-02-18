#include <bits/stdc++.h>

using namespace std;

struct User {
  int lv;
  char name[17];
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int p, m;
  cin >> p >> m;

  vector<pair<int, vector<User>>> vec;
  while (p--) {
    User user;
    cin >> user.lv >> user.name;
    bool found = false;
    for (int i = 0; i < vec.size(); i++) {
      auto& [lv, room] = vec[i];
      if (room.size() == m) continue;
      if (abs(lv - user.lv) <= 10) {
        found = true;
        room.emplace_back(user);
        break;
      }
    }
    if (!found) {
      vec.push_back({user.lv, vector<User>()});
      auto& room = vec.back();
      room.second.reserve(m);
      room.second.emplace_back(user);
    }
  }

  for (auto& v : vec) {
    auto& room = v.second;
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
