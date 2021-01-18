#include <iostream>
#include <math.h>
#include <stack>
#include <string.h>
using namespace std;
// int mod = 1000000007;


int main() {
	// unsigned long long int sum=0;
	int n;
	cin >> n;
	while (n--)
	{
		string s;
		cin >> s;
		while (true)
		{
			if (s.empty())
			{
				cout << 1 << endl;
				break;
			}
			int i = -1;
			for (int j = 0; j<s.size(); j++)
			{
				if (s[j] == '(' && s[j + 1] == ')' || s[j] == '[' && s[j + 1] == ']' || s[j] == '{' && s[j + 1] == '}')
				{
					i = j;
					break;
				}
			}
			if (i == -1)
			{
				cout << 0 << endl;
				break;
			}
			if (s.size() == 2)
			{
				cout << 1 << endl;
				break;
			}

			s.erase(s.begin() + i, s.begin() + i + 2);
			// cout<<s<<endl;
		}

	}
}