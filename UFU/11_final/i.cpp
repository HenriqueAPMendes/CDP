#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define endl '\n'
#define vi vector<int>
#define ii pair<int,int>
#define vii vector<ii>
#define INF 1234567890213213

vector<vii> adj;
vi taken;
int n, m;

int prim(){
	priority_queue<ii> pq;
	taken[0] = 1;
	for (auto &[w,v] : adj[0])
		if (!taken[v]) pq.push({-w, -v});

	int cost = 0;
	while(!pq.empty()){
		int w = -pq.top().first;
		int u = -pq.top().second;
		pq.pop();
		if (!taken[u]){
			cost += w;
			taken[u] = 1;
			for (auto &[w,v] : adj[u])
				if (!taken[v]) pq.push({-w, -v});
		}
	}
	return cost;
}

void solve(int t){
	cin >> n >> m;
	adj = vector<vii>(n);
	taken = vi(n);

	int cnt = 0;
	map<string,int> s2u;
	while(m--){
		string s1, s2; int w;
		cin >> s1 >> s2 >> w;
		if (!s2u.count(s1)) s2u[s1] = cnt++;
		if (!s2u.count(s2)) s2u[s2] = cnt++;
		int u = s2u[s1];
		int v = s2u[s2];
		adj[u].push_back({w,v});
		adj[v].push_back({w,u});
	}

	int ans = prim();
	cout << ans << endl;
	if (t) cout << endl;
}

signed main(){
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(0);

	int t; cin >> t;
	while(t--) solve(t);

	return 0;
}

