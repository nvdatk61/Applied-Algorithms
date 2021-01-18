#include<bits/stdc++.h>
using namespace std;


int X[100000], Y[100000];

int solution(int m, int n) {
	if (m == 0 || n == 0)
		return 0;
	else if (Y[m - 1] == X[n - 1])
		return 1 + solution(m - 1, n - 1);
	else
		return max(solution(m - 1, n), solution(m, n - 1));
}

int main() {
	int n, m;
	cin >> m >> n;
	for (int i = 1; i <= n; i++) {
		cin >> X[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> Y[i];
	}
	cout << solution(m, n) << endl;
	system("pause");
}