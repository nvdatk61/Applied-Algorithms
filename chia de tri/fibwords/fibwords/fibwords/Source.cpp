﻿#include<bits/stdc++.h>
using namespace std;

string p;
string f[2];
long long save[102];

int nOcurr(string a, string s) {
	int ans = 0;
	for (int i = 0; i + a.size() - 1<s.size(); i++) {
		int ok = 1;
		for (int j = 0; j<a.size(); ++j) {
			if (a[j] != s[i + j]) {
				ok = 0;
				break;
			}
		}
		ans += ok;
	}
	return ans;
}

string last(int k, int n) {
	if (n <= 1) {
		return f[n];
	}
	string ans = last(k, n - 2);
	if (ans.size() == k) return ans;
	return last(k - ans.size(), n - 1) + ans;
}
string first(int k, int n) {
	if (n <= 1) {
		return f[n];
	}
	string ans = first(k, n - 1);
	if (ans.size() == k) return ans;
	return ans + first(k - ans.size(), n - 2);
}

long long cnt(int n) { 
	if (n <= 1) {
		return f[n] == p ? 1 : 0;
	}
	if (save[n] != -1) {
		return save[n];
	}
	long long ans = cnt(n - 1) + cnt(n - 2);
	string t = last(p.size() - 1, n - 1) + first(p.size() - 1, n - 2);
	ans += nOcurr(p, t);
	save[n] = ans;
	return ans;
}

int main()
{
	f[0] = '0', f[1] = '1';
	int n, t = 0;
	while (cin >> n >> p) {
		t++;
		for (int i = 0; i <= 100; i++) {
			save[i] = -1;
		}
		cout << "Case " << t << ": " << cnt(n);
		
	}
}