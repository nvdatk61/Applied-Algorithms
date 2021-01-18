#include <iostream>
using  namespace std;

int main() {
	int N;
	cin >> N;
	int a[1000001];
	long long int sum[1000001];
	for (int i = 0; i < N; i++) {
		cin >> a[i];
		sum[i] = 0;
	}
	sum[0] = a[0];
	int max = sum[0];
	int min = 0;
	if (min > a[0])
		min = a[0];
	for (int i = 1; i < N; i++) {
		sum[i] = sum[i - 1] + a[i];
		if (min > sum[i]) {
			min = sum[i];
		}
		if (max<sum[i])
		{
			max = sum[i];
		}
	}
	cout << max-min << endl;
	return 0;
}