#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define ii pair<int,int>
#define iii pair<int, ii>
#define vi vector<int>
#define vii vector<ii>
#define vvii vector<vii>
#define viii vector<iii>
#define endl '\n'
#define MAX 112345

vvii adj;
vi vis;

int prim(){
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    vis[0] = 1;
    for (auto [w,v] : adj[0])
        if (!vis[v]) pq.push({w,v});
    
    int cost = 0;
    while(!pq.empty()){
        auto [w,u] = pq.top(); pq.pop();
        if (!vis[u]){
            cost += w;
            vis[u] = 1;
            for (auto [w,v] : adj[u])
                if (!vis[v]) pq.push({w,v});
        }
    }
    return cost;
}

void dfs(int u, int c){
    vis[u] = c;
    for (auto [w,v] : adj[u])
        if (!vis[v]) dfs(v, c);
}

void solve(){
    int n, m;
    cin >> n >> m;
    adj = vvii(n);
    vis = vi(n);
    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        adj[a].push_back({c, b});
        adj[b].push_back({c, a});
    }

    // conta componentes
    int c = 0;
    for (int i = 0; i < n; i++){
        if (!vis[i]) dfs(i, ++c);
    }
    if (c > 1) { cout << "IMPOSSIBLE" << endl; return; }
    vis.assign(n,0);
    cout << prim() << endl;
}

signed main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    solve();
    return 0;
}
