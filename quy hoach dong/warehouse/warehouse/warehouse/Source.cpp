#include <bits/stdc++.h>
using namespace std;

int n, _time, d;
int a[100011], t[100011], F[1001][101];
bool comp[1001][101];
int solution(int i, int k)
{
	if (k < t[i])
		return 0;
	if (comp[i][k])
		return F[i][k];
	int res = a[i];
	for (int j = i + 1; j <= i + d && j <= n; j++) {
		if (j >= 0) {
			res = max(res, solution(j, k - t[i]) + a[i]);
		}
	}
	F[i][k] = res;
	comp[i][k] = 1;
	return res;
}
int main()
{
	cin >> n >> _time >> d;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) cin >> t[i];
	int res = 0;
	/*for (int i=1;i<=d;i++){
	_max=solution(n-1-i,_time);
	}*/
	for (int i = 1; i <= n; i++) {
		res = max(res, solution(i, _time));
	}
	cout << res << endl;
	system("pause");
}