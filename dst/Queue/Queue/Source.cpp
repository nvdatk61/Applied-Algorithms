#include <iostream>
#include <queue>
using namespace std;
int main() {
	int n;
	cin >> n;
	int *arr =new int[n] ;
	int *res =new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	for (int i = 0; i < n ; i++)
	{
		res[i] = -1;
		for (int j = n-1; j >= i; j--)
		{
			if (arr[i] > arr[j]) {
				res[i] = j - i - 1;
				break;
			}
		
		}
		
	}
	for (int i = 0; i < n; i++)
	{
		cout << res[i] <<" ";
	}
	cout << endl;
	return 0;
}