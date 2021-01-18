#include<bits\stdc++.h>
using namespace std;

int n, m, credit[17];
int c[17], e[17], cnt[17];
int best=2e9, res[17];

int f()
{
	int _max = 0;
	for (int i = 1; i <= m; i++)
	{
		int total = 0;
		for (int j = 1; j <= n; j++)
		{
			if (e[j] == i)
				total += credit[j];
		}
		if (total >= _max) _max = total;
	}
	return _max;
}
void Try(int i) {
	if (i > n) {
		for (int j = 1; j <= m; j++)
		{
			if (cnt[j] == 0) return;
		}
		best = min(best, f());
		return;
	}
	for (int j = 1; j <= m; j++)
	{
		e[i] = j;
		if (e[i] >= e[c[i]] && e[c[i]] != 0) continue;
		cnt[j] ++;
		Try(i + 1);
		cnt[j] --;
	}
	
	return;
}

void input() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		e[i] = 0;
		cin >> credit[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int k;
			cin >> k;
			if (k == 1) c[i] = j;
		}
	}
	for (int i = 1; i <= m; i++) {
		cnt[i] = 0;
		
	}
}
int main() {
	input();
	Try(1);
	cout << best;
	system("pause");
}