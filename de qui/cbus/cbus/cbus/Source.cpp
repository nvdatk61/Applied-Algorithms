#include <bits/stdc++.h>
using namespace std;

int n, k;
int c[44][44];
int visited[44];
int x[44];
int best = 2e9;

void duyet(int i, int h, int sum) {
	if (i > 2 * n) {
		best = min(best, sum + c[x[2 * n]][0]);
		return;
	}
	if (sum + (2 * n + 1 - i) * 1 >= best) return;
	for (int j = 1; j <= 2 * n; ++j) {
		if (visited[j]) continue;
		if (h + (j <= n) - (j>n) > k) continue;
		if (j > n && !visited[j - n]) continue;
		x[i] = j;
		visited[j] = 1;
		duyet(i + 1, h + (j>n ? -1 : 1), sum + c[x[i - 1]][x[i]]);
		visited[j] = 0;
	}

}
int main() {
	cin >> n >> k;
	for (int i = 0; i <= 2 * n; ++i) {
		for (int j = 0; j <= 2 * n; ++j) cin >> c[i][j];
	}
	duyet(1, 0, 0);
	cout << best;
	system("pause");
}