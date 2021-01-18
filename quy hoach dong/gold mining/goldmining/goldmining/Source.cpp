#include<bits/stdc++.h>
using namespace std;

int n, L1, L2, F[100000], a[100000];
bool comp[100000];
//memset(comp,0,sizeof(comp));
int solution(int i) {
	if (i<L1) return a[i];
	if (comp[i]) {
		return F[i];
	}
	int res = solution(i - L1) + a[i];
	for (int j = i - L2; j <= i - L1; j++) {
		if (j >= 0) res = max(res, solution(j) + a[i]);
	}
	F[i] = res;
	comp[i] = 1;
	return res;
}

int main() {
	cin >> n >> L1 >> L2;
	for (int i = 0; i<n; i++) {
		cin >> a[i];
	}
	int _max = 0;
	for (int i = 0; i<L1; i++)
	{
		_max = solution(n - 1 - i);
	}
	for (int i = 0; i<n; i++) {
		_max = max(_max, F[i]);
	}
	cout << _max << endl;
	system("pause");
}