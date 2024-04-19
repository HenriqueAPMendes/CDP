#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define vi vector<int>
#define ii pair<int,int>
#define vii pair<int,int>

vector<vi> adj, adjT;
vi scc, ts, vis;

void dfs1(int u){
	vis[u] = 1;
	for (auto v : adj[u]) 
		if (!vis[v]) dfs1(v);
	
	ts.push_back(u);
}

void dfs2(int u, int c){
	scc[u] = c;
	for (auto v : adjT[u])
		if (!scc[v]) dfs2(v,c);
}

int main(){
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(0);
		
	int n, m;
	cin >> n >> m;

	adj = adjT = vector<vi>(2*m);
	scc = vis = vi(2*m);

	for (int i = 0; i < n; i++){
		char c1, c2;
		int t1, t2;
		cin >> c1 >> t1 >> c2 >> t2;
		t1--; t2--;
		if (c1 == '+' and c2 == '+'){
			adj[t1+m].push_back(t2);
			adj[t2+m].push_back(t1);
			adjT[t2].push_back(t1+m);
			adjT[t1].push_back(t2+m);
		}
		else if (c1 == '+' and c2 == '-'){
			adj[t1+m].push_back(t2+m);
			adj[t2].push_back(t1);
			adjT[t2+m].push_back(t1+m);
			adjT[t1].push_back(t2);
		}
		else if (c1 == '-' and c2 == '-'){
			adj[t1].push_back(t2+m);
			adj[t2].push_back(t1+m);
			adjT[t2+m].push_back(t1);
			adjT[t1+m].push_back(t2);
		}
		else { // - +
			adj[t1].push_back(t2);
			adj[t2+m].push_back(t1+m);
			adjT[t2].push_back(t1);
			adjT[t1+m].push_back(t2+m);
		}
	}

	for (int i = 0; i < 2*m; i++)
		if (!vis[i]) dfs1(i);

	reverse(ts.begin(), ts.end());

	int c = 1;
	for (auto u : ts)
		if (!scc[u]) dfs2(u, c++);
	
	bool ok = true;
	vector<char> ans(m);
	for (int i = 0; i < m; i++){
		if (scc[i] == scc[i+m]) ok = false;
		if (scc[i] > scc[i+m]) ans[i] = '+';
		else ans[i] = '-';
	}

	if (!ok) { cout << "IMPOSSIBLE" << endl; return 0; }

	for (auto c : ans) cout << c << ' ';
	cout << endl;

	return 0;
}

