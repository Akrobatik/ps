// Title : 폴더 정리 (large)
// Link  : https://www.acmicpc.net/problem/22861 
// Time  : 132 ms
// Memory: 53332 KB

#include <bits/stdc++.h>

using namespace std;

struct Dir {
  Dir() : par(-1) {}

  int par;
  set<int> dirs, files;
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<Dir> dirs;
  vector<string> dname, fname;
  map<string, int> did, fid;

  auto GetDirId = [&](const string& s) {
    auto it = did.find(s);
    if (it != did.end()) return it->second;
    int id = did.size();
    dirs.emplace_back();
    dname.push_back(s);
    return did[s] = id;
  };

  auto GetFileId = [&](const string& s) {
    auto it = fid.find(s);
    if (it != fid.end()) return it->second;
    int id = fid.size();
    fname.push_back(s);
    return fid[s] = id;
  };

  GetDirId("main");

  int n, m;
  cin >> n >> m;

  int nm = n + m;
  while (nm--) {
    string s1, s2;
    int type;
    cin >> s1 >> s2 >> type;
    auto i1 = GetDirId(s1);
    if (type == 1) {
      auto i2 = GetDirId(s2);
      dirs[i1].dirs.insert(i2);
      dirs[i2].par = i1;
    } else {
      auto i2 = GetFileId(s2);
      dirs[i1].files.insert(i2);
    }
  }

  int k;
  cin >> k;
  while (k--) {
    string s1, s2;
    cin >> s1 >> s2;
    if (auto pos = s1.find_last_of('/'); pos != string::npos) s1 = s1.substr(pos + 1);
    if (auto pos = s2.find_last_of('/'); pos != string::npos) s2 = s2.substr(pos + 1);
    auto i1 = GetDirId(s1), i2 = GetDirId(s2);

    auto& src = dirs[i1];
    auto& dst = dirs[i2];
    for (auto id : src.dirs) dirs[id].par = i2;
    dst.dirs.insert(src.dirs.begin(), src.dirs.end());
    dst.files.insert(src.files.begin(), src.files.end());
    if (src.par != -1) dirs[src.par].dirs.erase(i1);
  }

  vector<vector<int>> memo(dname.size(), vector<int>(fname.size()));
  vector<bool> visited(dname.size());

  function<vector<int>(int)> Count = [&](int id) {
    auto& res = memo[id];
    if (visited[id]) return res;
    visited[id] = true;
    for (auto e : dirs[id].files) ++res[e];
    for (auto e : dirs[id].dirs) {
      auto cnt = Count(e);
      for (int i = 0; i < fname.size(); i++) res[i] += cnt[i];
    }
    return res;
  };

  int q;
  cin >> q;
  while (q--) {
    string s;
    cin >> s;
    if (auto pos = s.find_last_of('/'); pos != string::npos) s = s.substr(pos + 1);
    auto cnt = Count(GetDirId(s));
    int unq = 0, sum = 0;
    for (int i = 0; i < fname.size(); i++) {
      if (cnt[i] == 0) continue;
      sum += cnt[i];
      ++unq;
    }
    cout << unq << " " << sum << "\n";
  }

  return 0;
}
