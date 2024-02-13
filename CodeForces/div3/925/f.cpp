#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define vi vector<int>
#define ii pair<int,int>
#define iii pair<int,ii>
#define endl '\n'

vector<vi> adj;
vi vis;
int n;

// is there a cycle on the graph?
//FALTOU TEMPO

bool dfs(int u, int p){
    vis[u] = 1;
    for (auto &v : adj[u]){
        if(!vis[v]) return dfs(v,u);
        else if (v != p) {
            cout << "found cycle" << endl;
            return false;
        }
    }
    return true;
}

bool cycle(){
    bool ans = true;
    for (int i = 1; i <= n; i++)
        if (!vis[i]) ans &= dfs(i, -1);
    
    return !ans;
}


void solve(){
    int k;
    cin >> n >> k;
    
    vi a(n);
    vis = vi(n+1);
    adj = vector<vi>(n+1);
    
    for (int i = 0; i < k; i++){
        for (int j = 0; j < n; j++) cin >> a[i];

        for (int j = 1; j < n-1; j++) adj[a[i]].push_back(a[i+1]);
    }

    bool valid = cycle();
    cout << (valid ? "YES" : "NO") << endl;
}

signed main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int t; cin >> t;
    while(t--) solve();

    return 0;
}