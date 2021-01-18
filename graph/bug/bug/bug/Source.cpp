#include <bits/stdc++.h>
using namespace std;

const int MAX = 2005;

int N;		// số lượng bọ
int I;		// số lượng tương tác
int Answer;	// kết quả 1 : nếu tồn tại tình dục đồng giới

int mt[MAX][MAX];	// Đánh dấu tồn tại cạnh giữa 2 điểm
int Mark[MAX];			// Mảng đánh dấu loại các con bọ

void DFS(int u, int before, int type)
{
	Mark[u] = type;
	for (int i = 1; i <= mt[u][0] && !Answer; i++)
	{
		int v = mt[u][i];
		if (Mark[v] == -1)
		{
			// Nếu chưa duyệt thì duyệt và đánh dấu loại khác với điểm trước đó
			DFS(v, u, !type);
		}
		else if (v != before && Mark[v] == type)
		{
			// Nếu gặp một điểm mà được xét rồi và cùng loại thì có tình dục đồng giới
			// Lúc này dừng lại luôn.
			Answer = 1;
			return;
		}
	}
}

int main()
{
	//ios::sync_with_stdio(false);
	int T;
	cin >> T;
	for (int tc = 0; tc < T; tc++)
	{
		Answer = 0;
		cin >> N >> I;
		for (int i = 0; i <= N; i++)
		{
			Mark[i] = -1;
			for (int j = 0; j <= N; j++)
				mt[i][j] = 0;
		}

		int a, b, m;
		for (int i = 1; i <= I; i++)
		{
			cin >> a >> b;

			m = ++mt[a][0];
			mt[a][m] = b;

			m = ++mt[b][0];
			mt[b][m] = a;
		}

		// Tìm những điểm chưa được duyệt thì sẽ duyệt
		for (int i = 1; i <= N; i++)
			if (Mark[i] == -1)
				DFS(i, -1, 0);

		// Đầu ra
		cout << "Scenario #" << tc + 1 << ":" << endl;
		if (Answer) cout << "Suspicious bugs found!" << endl;
		else cout << "No suspicious bugs found!" << endl;
	}
	return 0;
}

/*
#include<bits/stdc++.h>
using namespace std;

vector<int> adj[100011];
int n ,m, color[100011], ok ;

int dfs(int x, int c){
    color[x]=c;
    for (int y : adj[x]){
        if (color[y]==-1) dfs (y , 1-c);
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        for (int x=1; x<=n;x++) adj[x].clear();
        cin >> n >> m;
        while(m--){
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for (int x=1; x<=n;++x) color[x]=-1;
        for (int x=1; x<=n;++x){
            if (color[x]==-1) dfs(x, 0);
        }
        int ok =1;
        for (int x=1;x<=n;++x) for (int y: adj[x]){
            if (color[x] == color[y]) ok = 0;
        }
        cout << "Scenario #" << t+1  << ":"<< endl;
    	if (ok) cout << "Suspicious bugs found!" << endl;
    	else cout << "No suspicious bugs found!" << endl;
    }
	}
*/