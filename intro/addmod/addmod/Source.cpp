#include <iostream>
using namespace std;
int main() {
	unsigned long long int a, b;
	cin >> a >> b;
	unsigned int c = 100000007;
	cout << (a + b) % c << endl;
	system("pause");
	return 0;
}