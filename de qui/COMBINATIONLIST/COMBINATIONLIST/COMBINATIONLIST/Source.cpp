#include <iostream>
#define max 10000
using namespace std;

int n, m, z, dem = 0;
int a[max];

void Try(int k) {
	for (int i = a[k - 1] + 1; i <= n - m + k; i++) {
		a[k] = i;
		if (k == m) {
			dem += 1;
			if (dem == z) {
				for (int j = 1; j <= m; j++)
					cout << a[j] << " ";
			}
		}

		else
			Try(k + 1);
	}
}
int main() {
	cin >> n >> m >> z;
	Try(1);
	if (dem < z)
		cout << -1;
	system("pause");
}