// Title : shapey
// Link  : https://www.acmicpc.net/problem/33563
// Time  : 0 ms
// Memory: 2220 KB

#include <bits/stdc++.h>

using namespace std;

map<char, map<char, pair<int, int>>> mp;
vector<string> cmds;

vector<array<pair<char, char>, 4>> Parse(const string& s) {
  vector<array<pair<char, char>, 4>> layers;
  istringstream iss(s);
  string layer;
  while (getline(iss, layer, ':')) {
    auto& cur = layers.emplace_back();

    for (int i = 0; i < 4; i++) {
      if (layer[i << 1] == '-') continue;
      cur[i].first = layer[i << 1];
      cur[i].second = layer[(i << 1) + 1];
    }
  }
  return layers;
}

bool Check(const vector<array<pair<char, char>, 4>>& layers) {
  for (auto& layer : layers) {
    for (auto [shape, color] : layer) {
      if (!shape) continue;
      if (mp[shape].empty() ||
          (color == 'u' && !mp[shape].contains('u'))) {
        return false;
      }
    }
  }

  int n = layers.size();
  for (int i = 1; i < n; i++) {
    bool ok = false;
    for (int j = 0; !ok && j < 4; j++) {
      ok = (layers[i - 1][j].first && layers[i][j].first);
    }
    if (!ok) return false;
  }

  return true;
}

void InsertCmd(int t, int i, int j, int k) {
  ostringstream oss;
  oss << t << " " << i << " " << j << " ";
  if (t == 4) {
    oss << (char)k;
  } else {
    oss << k;
  }
  cmds.push_back(oss.str());
}

void MoveUnit(char shape, char color, int idx, int reg, bool first) {
  bool colorize;
  int i, j;
  auto it = mp[shape].find(color);
  if (it != mp[shape].end()) {
    colorize = false;
    tie(i, j) = it->second;
  } else {
    colorize = true;
    tie(i, j) = mp[shape].begin()->second;
  }

  // Move layer to 11-3
  if (j == 3) {
    InsertCmd(2, i, 11, 2);
    InsertCmd(2, 11, 11, 2);
  } else {
    InsertCmd(2, i, 11, 3 - j);
  }
  // Split to unit
  InsertCmd(1, 11, 11, 12);
  InsertCmd(2, 11, 11, 3);
  InsertCmd(1, 11, 11, 12);
  // Colorize
  if (colorize) {
    InsertCmd(4, 11, 11, color);
  }
  // Move to 11-idx
  if (idx != 2) {
    InsertCmd(2, 11, 11, (idx + 2) % 4);
  }
  // Move to reg-idx
  if (first) {
    InsertCmd(2, 11, reg, 2);
    InsertCmd(2, reg, reg, 2);
  } else {
    InsertCmd(3, reg, 11, reg);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  string s;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> s;
    for (int j = 0; j < 8; j += 2) {
      if (s[j] == '-') continue;
      mp[s[j]][s[j + 1]] = {i, j >> 1};
    }
  }
  cin >> s;
  auto dst = Parse(s);

  if (!Check(dst)) {
    cout << "-1";
    return 0;
  }

  for (int i = 0; i < dst.size(); i++) {
    bool first = true;
    for (int j = 0; j < 4; j++) {
      auto [shape, color] = dst[i][j];
      if (!shape) continue;
      MoveUnit(shape, color, j, 100 - i, first);
      first = false;
    }
  }

  for (int i = 1; i < dst.size(); i++) {
    InsertCmd(3, 100, 100 - i, 100);
  }

  cout << cmds.size() << "\n";
  for (auto& cmd : cmds) {
    cout << cmd << "\n";
  }

  return 0;
}
