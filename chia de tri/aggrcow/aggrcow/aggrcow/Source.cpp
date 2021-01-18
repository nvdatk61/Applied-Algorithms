#include<bits/stdc++.h>
using namespace std;

int a[1000000];
bool f(int k, int c, int n)
{
	int i = 0;
	for (int t = 1; t <= c; t++) {
		if (i >= n) return false;
		int post = a[i];
		while (i<n && a[i] - post < k) ++i;
	}
	return true;
}
int main()
{
	std::ios::sync_with_stdio(false);
	int t;
	cin >> t;
	int n, c;
	while (t--) {
		cin >> n >> c;
		for (int i = 0; i<n; i++) {
			cin >> a[i];
		}
		sort(a, a + n);
		int l = 0, h = 1e9, ans = -1;
		while (l <= h) {
			int m = (h + l) / 2;
			if (f(m, c, n)) {
				ans = m;
				l = m + 1;
			}
			else h = m - 1;
		}
		cout << ans << endl;
	}
	system("pause");
}