#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define vi vector<int>
#define ii pair<int,int>
#define vii vector<ii>

vector<vi> adj;
vi comp;

void dfs(int u, int c){
	comp[u] = c;
	for (auto v : adj[u])
		if (!comp[v]) dfs(v, c);
}

int main(){
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(0);

	int n, m;
	cin >> n >> m;

	vi initial(n);
	vii switches(n, {-1,-1});
	adj = vector<vi>(2*m);
	comp = vi(2*m);
	
	for (int i = 0; i < n; i++) cin >> initial[i];
	
	for (int i = 0; i < m; i++){
		int x; cin >> x;
		// switch i
		while(x--){
			int porta; cin >> porta; porta--;
			if (switches[porta].first == -1)
				switches[porta].first = i;
			else switches[porta].second = i;
		}
	}
	// construir o grafo
	for (int i = 0; i < n; i++){
		int a = switches[i].first;
		int b = switches[i].second;
		if (initial[i] == 1){
			adj[a].push_back(b);
			adj[b].push_back(a);
			adj[a+m].push_back(b+m);
			adj[b+m].push_back(a+m);
		}
		else {
			adj[a].push_back(b+m);
			adj[b+m].push_back(a);
			adj[a+m].push_back(b);
			adj[b].push_back(a+m);
		}
	}

	// dfs para marcar componentes
	for (int i = 0; i < 2*m; i++)
		if(!comp[i]) dfs(i, i+1);

	bool ok = true;
	for (int i = 0; i < m; i++)
		if (comp[i] == comp[i+m]) ok = false;

	cout << (ok ? "YES" : "NO") << endl;

	return 0;
}
