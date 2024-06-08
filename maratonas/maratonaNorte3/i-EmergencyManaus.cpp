#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define endl '\n'
#define vi vector<int>
#define ii pair<int,int>

vector<vi> adj;
vi vis, isFilho;

void dfs(int u){
    vis[u] = 1;
    for (auto v : adj[u])
        if (!vis[v]) dfs(v);
}

void solve(){
    int v, e, s;
    cin >> v >> e >> s;
    s--;
    adj = vector<vi>(v);
    vis = isFilho = vi(v);
    while(e--){
        int x, y;
        cin >> x >> y;
        isFilho[y-1] = 1;
    }
    
    int ans = 0;
    for (int i = 0; i < v; i++)
        if (i != s && !isFilho[i]) ans++;
    cout << ans << endl;

}

signed main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    solve();
    return 0;
}