#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define endl '\n'
#define ii pair<int,int>
#define vi vector<int>

vi ts, vis;
vector<vi> adj;
bool hasCycle;

void dfs(int u){
    if (vis[u] == 1) hasCycle = true;
    if (vis[u]) return;
    vis[u] = 1;
    for (auto &v : adj[u]) 
        dfs(v);

    vis[u] = 2;
    ts.push_back(u);
    
}

signed main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n, m;
    cin >> n >> m;
    adj = vector<vi>(n+1);
    vis = vi(n+1);
    while(m--){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }
    hasCycle = false;
    for (int i = 1; i <= n; i++) dfs(i);

    if (hasCycle) cout << "IMPOSSIBLE";
    else
        for (auto it = ts.rbegin(); it != ts.rend(); it++) cout << *it << ' ';
    cout << endl;

    return 0;
}