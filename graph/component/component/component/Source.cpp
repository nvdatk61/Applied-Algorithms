#include <bits/stdc++.h>
#include <vector>
using namespace std;

int n, m, u, v;
vector<int> a[1000001];
vector<int> component(1000001, -1);

void find(int cur_comp, int u)
{
	if (component[u] != -1)
		return;
	component[u] = cur_comp;
	for (int i = 0; i < a[u].size(); i++) {
		int v = a[u][i];
		find(cur_comp, v);
	}
}

int main()
{
	std::ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		cin >> u >> v;
		a[v].push_back(u);
		a[u].push_back(v);
	}
	int dem = 0;
	for (int u = 1; u <= n; u++) {
		if (component[u] == -1) {
			find(dem, u);
			dem++;
		}
	}
	cout << dem << endl;
	system("pause");
}