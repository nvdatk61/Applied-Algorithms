#include<bits/stdc++.h>
using namespace std;



int t, n, f, r[10000];


void input()
{
	cin >> t;
	while (t--) {
		cin >> n >> f;
		for (int i = 1; i <= n; i++) {
			cin >> r[i];
		}
	}
}
int main()
{
	input();
	double l = 0; h = 1e18;
	for (rp = 100; rp--;) {
		double m = (l + h) / 2;
		if (f(m)) l = m;
		else h = m;
	}
	cout << fixed << setprecision(6) << l;
}