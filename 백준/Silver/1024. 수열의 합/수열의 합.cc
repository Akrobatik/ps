#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, l, result;
	cin >> n >> l;

	result = -1;
	for (l; l <= 100; l++) {
		if (l % 2 == 0) {
			if ((n / l) * l + l / 2 == n) {
				result = (n / l) - l / 2 + 1;
				if (result >= 0) break;
			}
		}
		else {
			if ((n / l) * l == n) {
				result = n / l - (l - 1) / 2;
				if (result >= 0) break;
			}
		}
	}

	if (result < 0) {
		cout << -1 << endl;
	}
	else {
		for (int i = 0; i < l; i++) {
			cout << result + i;
			if (i != l - 1) {
				cout << " ";
			}
		}
		cout << endl;
	}

	return 0;
}