#include <bits\stdc++.h>
#define max 20
using namespace std;

int n, z;
int d[max] = { 0 }; //danh dau mang duyet cac phan tu
int dem = 0;

void Try(int *a, int k) {
	for (int i = 1; i <= n; i++) {
		// kiem tra phan tu chua duoc chon thi se danh dau
		if (!d[i]) {
			a[k] = i; //luu 1 phan tu vao hoan vi
			d[i] = 1; // danh dau phan tu do da duoc chon		
			if (k == n) { // danh dau kiem tra da co hoan vi thi xuat 	
				dem ++;
				if (dem == z) {
					for (int j = 1; j <= n; j++) {
						cout << a[j] << " ";
					}
					return;
				}
			}
			else
				Try(a, k + 1);
			d[i] = 0;
		}
	}
}

int main() {
	cin >> n >> z;
	int *a = new int[n];
	Try(a, 1);
	if (dem<z)
	{
		cout << -1;
	}
	system("pause");
}
