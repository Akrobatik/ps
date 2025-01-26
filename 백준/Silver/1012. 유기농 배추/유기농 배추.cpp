#include <bits/stdc++.h>

using namespace std;

vector<uint8_t> g;
int w, h;

void InitGraph() {
	int x, y, n;
	cin >> w >> h >> n;
	g.resize(w * h, 0);
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		g[y * w + x] = 1;
	}
}

void Traverse(int sx, int sy) {
	queue<pair<int, int>> q;
	q.push(make_pair(sx, sy));
	while (!q.empty()) {
		auto [x, y] = q.front();
		q.pop();

		if (g[y * w + x]) {
			g[y * w + x] = 0;

			for (int i = 0; i < 4; i++) {
				static constexpr int vx[] = { 1, 0, -1, 0 };
				static constexpr int vy[] = { 0, 1, 0, -1 };
				int xx = x + vx[i];
				int yy = y + vy[i];
				if (0 <= xx && xx < w && 0 <= yy && yy < h &&
					g[yy * w + xx]) {
					q.push(make_pair(xx, yy));
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		InitGraph();

		int result = 0;
		for (int j = 0; j < g.size(); j++) {
			int x = j % w;
			int y = j / w;
			if (g[y * w + x]) {
				Traverse(x, y);
				result++;
			}
		}

		cout << result << endl;
	}

	return 0;
}