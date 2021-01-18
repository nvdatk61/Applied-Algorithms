#include<bits/stdc++.h>
#include<queue>
using namespace std;
int n, m, u, v;
vector<int> a[1000001];
vector<bool> vt(1000001, false);
vector<int> d(1000001, -1);
queue<int> Q;

int BFS(int u)
{
	Q.push(u);
	vt[u] = true;
	d[u] = 1;
	while (!Q.empty())
	{
		int v = Q.front();
		Q.pop();
		for (int i = 0; i < a[v].size(); i++)
		{
			int x = a[v][i];
			if (!vt[x] && d[x] == -1) {
				Q.push(x);
				vt[x] = true;
				d[x] = 1 - d[v];
			}
			else {
				if (vt[x] && d[x] == d[v]) return 0;
			}
		}
	}
	return 1;
}
int main()
{
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		cin >> u >> v;
		a[u].push_back(v);
		a[v].push_back(u);
	}
	int aws = 1;
	for (int i = 1; i <= n; i++)
	{
		if (vt[i] == false)
		{
			if (BFS(i) == 0)
			{
				aws = 0;
				break;
			}
		}
	}
	cout << aws << endl;
	system("pause");
}