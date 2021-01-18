#include <bits\stdc++.h>
using namespace std;

int n, m, x, y;
vector<int> a[1000];
vector<int> low(1000), num(1000, -1);
int curnum = 0;
vector<pair<int, int>>bridges;

int find(int x, int y) {
	low[x] = num[x] = curnum++;
	for (int i = 0; i < a[x].size(); i++) {

	}
}
void main() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		cin >> x >> y;
	}
	a[1].push_back(10);
	a[10].push_back(2);
	a[10].push_back(3);
}