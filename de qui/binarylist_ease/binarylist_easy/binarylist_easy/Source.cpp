#include <iostream>
using namespace std;

void Try(int *a, int k, int n) {
	for (int i = 0; i <= 1; i++)
	{
		a[k] = i;
		if (k == n-1) {
			for (int j = 0; j < n; j++) {
				cout << a[j];
			}
			cout << "\n";
		}
		else Try( a,k + 1,n);
	}
}
int main() {
	int n;
	cin >> n;
	int *a = new int[n];
	Try( a , 0, n );
	system("pause");
	return 0;
}