#include <iostream>
using namespace std;
int main() {
	unsigned long long a, a1, a2, b, b1, b2, c1, c2;
	cin >> a;
	cin >> b;
	a1 = a / 10;
	a2 = a - (a1 * 10);
	b1 = b / 10;
	b2 = b - (b1 * 10);
	c1 = (a2 + b2) / 10;
	c2 = (a2 + b2) - (c1 * 10);
	if (a1 + b1 + c1 == 0) {
		cout << c2;
	}
	else {
		cout << a1 + b1 + c1 << c2;
	}
	system("pause");
	return 0;
}