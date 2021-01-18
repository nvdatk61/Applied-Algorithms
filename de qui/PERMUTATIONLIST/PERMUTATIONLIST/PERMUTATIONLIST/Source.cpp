#include <iostream>
#define max 10
using namespace std;

int n;
int a[max];
int d[max] = { 0 }; //danh dau mang duyet cac phan tu

void Try(int k) {
	for (int i = 1; i <= n; i++) { 
		if (!d[i]) {
			a[k] = i; //luu 1 phan tu vao hoan vi
			d[i] = 1; // danh dau phan tu do da duoc chon
			if (k == n) { // danh dau kiem tra da co hoan vi thi xuat
				for (int j = 1; j <= n; j++) {
					cout << a[j] << " ";
				}	
				cout << endl;
			}
			else
			{
				Try(k + 1);
			}
			d[i] = 0;
		}
	}
}

int main() {
	cin >> n;
	Try(1);
	system("pause");
}
