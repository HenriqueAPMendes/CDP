#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long int
#define vi vector<int>

struct node{
    int u, v, w;
    node(){ u = v = w = 0; }
    node(int _u, int _v, int _w) : u(_u), v(_v), w(_w) {}
};

vi vis, val;
vector<vector<node>> edges;

void dfs(int u){
    vis[u] = 1;
    for(auto &ch : edges[u])
        if(!vis[ch.v]){
            val[ch.v] = val[u] + ch.w; // cumprir a condicao
            dfs(ch.v);
        }
}

void solve(){
    int n, m;
    cin >> n >> m;

    edges = vector<vector<node>>(n+1);
    vis = val = vi(n+1);
    vector<node> cond(m); // condicoes

    for(int i = 0; i < m; i++){
        int u, v, w;
        cin >> u;
        cin >> v;
        cin >> w;
        edges[u].push_back(node(u,v,w)); // u - v = w
        edges[v].push_back(node(v,u,-w)); // v - u = -w
        cond[i] = node(u, v, -w);
    }

    for(int i = 1; i <= n; i++) 
        if(!vis[i]) dfs(i);
    
    bool valid = true;

    for(int i = 0; i < m; i++)
        if(cond[i].w != val[cond[i].u] - val[cond[i].v]) valid = false;
    
    cout << (valid ? "YES" : "NO") << endl;
}

signed main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
    
    return 0;
}
