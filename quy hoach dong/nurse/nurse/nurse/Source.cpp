#include <bits/stdc++.h>
using namespace std;

int n, k1, k2, f[1002], mod = 1e9 + 7;

int solution(int n)
{
	if (n <= 0) return 1;
	if (f[n] != -1) return f[n];
	int ans = 0;
	for (int x = k1; x <= k2 && x <= n; x++)
		ans = (ans + solution(n - x - 1)) % mod;
	f[n] = ans;
	return ans;
}

int main()
{
	cin >> n >> k1 >> k2;
	for (int i = 0; i <= n; i++) f[i] = -1;
	cout << solution(n) + solution(n - 1) << endl;
	system("pause");
}