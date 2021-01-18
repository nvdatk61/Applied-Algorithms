#include <bits/stdc++.h>
using namespace std;

int n, x[55], mark[55];
int c[55][55], best = 2e9;


void backtrack(int i, int sum, int curr) {
	if (i>n) {
		best = min(best, sum + c[curr][0]);
		return;
	}
	for (int t = 1; t <= n; ++t) {
		if (mark[t] == 0) {
			mark[t] = 1;
			x[i] = t;
			if (sum + c[curr][t] + c[t][t + n]<best)
				backtrack(i + 1, sum + c[curr][t] + c[t][t + n], t + n);
			mark[t] = 0;
		}
	}
}
int main() {
	cin >> n;
	for (int i = 0; i <= 2 * n; ++i) {
		for (int j = 0; j <= 2 * n; ++j) {
			cin >> c[i][j];
		}
	}
	backtrack(1, 0, 0);
	cout << best;
	system("pause");
}