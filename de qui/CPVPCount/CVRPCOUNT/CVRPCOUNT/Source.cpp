#include<bits\stdc++.h>
using namespace std;

int n, k, q;
int d[55], total[55];
int cnt[55];
int ans = 0;
int p = 1;
//int f()
//{
//	int _max = 0;
//	for (int i = 1; i <= k; i++) {
//		res = 0;
//		for (int j = 1; j <= n; j++)
//		{
//			if (e[j] == i)
//			{
//				res += d[j];
//			}
//		}
//		if (_max < res) _max = res;
//	}
//	return _max ;
//}
void Try(int i)
{
	if (i > n)
	{
		int res = 1;
		for (int v = 1; v <= k; v++) {
			if (cnt[v] == 0) {
				return;
			}
			else
			{
				for (int j = 1; j <= cnt[v]; j++) res *= j;
			}
		}
		ans += res;			
		return;
	}
	for (int j = 1; j <= k; j++) {
		if (total[j] + d[i] > q) continue;
		cnt[j]++;
		total[j] += d[i];
		Try(i + 1);
		cnt[j]--;
		total[j] -= d[i];
	}
	
}
void input()
{
	cin >> n >> k >> q;
	for (int i = 1; i <= n; i++) {
		cin >> d[i];
	}
	
	for (int i = 1; i <= k; i++) {
		cnt[i] = 0;
		total[i] = 0;
		p *= i;
	}
}

int main()
{
	input();
	Try(1);
	cout << ans/p;
	system("pause");
}