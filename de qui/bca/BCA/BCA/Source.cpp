#include <bits\stdc++.h>
using namespace std;

int n, m, k, c[55][55], e[55][55];
int x[55], best = 2e9, cnt[55];

bool check() {
	for (int i = 1; i <= n; i++) {
		if (c[x[i]][i] = false) {
			return false;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++) {
			if (x[i] == x[j] && e[i][j] == true)
			{
				return false;
			}
		}
	}
	return true;
}
int f() {
	for (int i = 1; i <= m; i++) cnt[i] = 0;
	for (int i = 1; i <= n; i++) ++cnt[x[i]];
	return *max_element(cnt + 1, cnt + 1 + m);
}
int duyet(int i) {
	if (i > n) {
		if (check()) {
			best = min(best, f());
		}
	}
	for (int j = 1; j <= n; j++) {
		x[i] = j;
		duyet(i + 1);
	}
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		cin >> k;
		while (k--) {
			int x;
			cin >> x;
			c[i][x] = true;
		}
	}
	cin >> k;
	while (k--)
	{
		int x, y;
		cin >> x >> y;
		c[x][y] = c[y][x] = true;
	}
	duyet(1);
	cout << best;
	system("pause");
}