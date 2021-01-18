#include <iostream>
using namespace std;

int n,z,h;
int dem=0;

void Try(int *a, int k) {
	for (int i = 0; i <= 1; i++)
	{
		a[k] = i;
		if (k == n - 1) {
				int tam = 0;
				for (int j = 0; j < n; j++){
					int count = 0;
					for (int e = j; e <= j+h-1 ; e++){
							count += a[e];
					}
					if (count == 0)
					{
						tam = 1;
						break;
					}
				}
				if (tam == 0)				
				{
					dem += 1;
					if (dem == z) {
						for (int j = 0; j < n; j++)
							cout << a[j] << " ";
						return;
					}

				}
		}
		else Try(a, k + 1 );
	}
}
int main() {
	cin >> n;
	cin >> z;
	cin >> h;
	int *a = new int[n];
	Try(a, 0);
	if (dem < z)
		cout << -1 << endl;
	system("pause");
	return 0;
}