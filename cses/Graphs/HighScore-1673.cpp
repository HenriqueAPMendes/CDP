#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define endl '\n'
#define ii pair<int,int>
#define iii pair<int, ii>
#define vi vector<int>

#define INF 11234567890123

vector<iii> edges;
vector<vector<ii>> adj, adjT;
vi vis1, vis2, dist, inv;


void dfs1(int u){
    vis1[u] = 1;
    for (auto &[v,w] : adj[u])
        if (!vis1[v]) dfs1(v);
}

void dfs2(int u){
    vis2[u] = 1;
    for (auto &[v,w] : adjT[u])
        if (!vis2[v]) dfs2(v);
}

signed main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n, m;
    cin >> n >> m;

    edges = vector<iii>(m);
    adj = adjT = vector<vector<ii>>(n+1);
    dist = vis1 = vis2 = inv = vi(n+1);

    for(int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        w = -w;
        adj[u].push_back({v,w});
        adjT[v].push_back({u,w});
        edges.push_back({w, {u,v}});
    }

    for (int i = 2; i <= n; i++) dist[i] = INF;

    for (int i = 0; i < n; i++)
        for (auto &[w,uv] : edges){
            int u = uv.first;
            int v = uv.second;
            dist[v] = min(dist[v], dist[u]+w);
        }

    for (auto &[w, uv] : edges){
        int u = uv.first;
        int v = uv.second;
        if (dist[u] + w < dist[v]) inv[v] = 1; // ????????
    }
            
    dfs1(1);
    dfs2(n);

    bool ok = true;

    if (ok) cout << -1 << endl;
    else cout << ans << endl;

    // cout << ans << endl;

    return 0;
}