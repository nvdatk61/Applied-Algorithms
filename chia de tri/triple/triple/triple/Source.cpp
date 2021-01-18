#include <bits/stdc++.h>
#define max 5000
using namespace std;

int n, s, a[max];


void input()
{
	cin >> n >> s;
	for (int i = 0; i<n; i++)
		cin >> a[i];
}
int main()
{
	input();
	vector<int> cnt(100011);
	long long ans = 0;
	for (int i = 1; i<n; i++) {
		cnt[a[i - 1]]++;
		for (int j = i + 1; j<n; j++) {
			//dem so luong a[z]==k-a[i]-a[j]
			if (s - a[i] - a[j] >= 0) ans += cnt[s - a[i] - a[j]];
		}
	}
	cout << ans;
	system("pause");
}