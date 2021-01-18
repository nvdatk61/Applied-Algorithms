#include <iostream>
#include <math.h>
#include <stack>
#include <string.h>
#include <cstdlib>
using namespace std;

int compare(const void* a, const void* b)
{
	const int* x = (int*)a;
	const int* y = (int*)b;
	if (*x > *y)
		return 1;
	else if (*x < *y)
		return -1;
	return 0;
}
int main() {
	unsigned long long n;
	cin >> n;
	int* a = new int[n];
	for (int i = 0; i<n; i++)
	{
		cin >> a[i];
	}
	qsort(a, n, sizeof(int), compare);
	for (int i = 0; i<n; i++)
	{
		cout << a[i] << " ";
	}
	system("pause");
	return 0;
}