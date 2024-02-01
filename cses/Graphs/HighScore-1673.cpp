#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define endl '\n'
#define ii pair<int,int>
#define vi vector<int>

#define INF 11234567890123

vector<vector<ii>> adj, adjT;
vi vis, dist, order;

int belmannFord(int s, int t, int n){
    for (int i = 1; i <= n; i++) dist[i] = INF;
    dist[s] = 0;
    for (int i = 1; i <= n; i++)
        for (int u = 1; u <= n; u++)
            for (auto &[v,w] : adj[u])
                dist[v] = min(dist[v], dist[u]+w);

    return dist[n];
}

void dfs1(int u){
    vis[u] = 1;
    for (auto &[v,w] : adj[u])
        if (!vis[v]) dfs1(v);
    
    order.push_back(u);
}

void dfs2(int u, int val){
    vis[u] = val;
    for (auto &[v,w] : adjT[u])
        if (!vis[v]) dfs2(v, val);
}

signed main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n, m;
    cin >> n >> m;

    adj = adjT = vector<vector<ii>>(n+1);
    dist = vis = vi(n+1);

    while(m--){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v,-w});
        adjT[v].push_back({u,-w});
    }

    int ans = -belmannFord(1, n, n);

    for (int u = 1; u <= n; u++)
        if (!vis[u]) dfs1(u);

    vis.assign(n+1,0);

    reverse(order.begin(), order.end());
    for (auto &u : order)
        if (!vis[u]) dfs2(u,u);

    bool hasPositiveCycle = false;
    for (int u = 1; u <= n; u++)
        for (auto &[v,w] : adj[u])
            if (dist[v] > dist[u]+w && vis[u] == vis[1]) hasPositiveCycle = true; // if u and n are in the same SCC

    if (hasPositiveCycle) cout << -1 << endl;
    else cout << ans << endl;

    // cout << ans << endl;

    return 0;
}