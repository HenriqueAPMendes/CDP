#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define endl '\n'
#define vi vector<int>
#define ii pair<int,int>
#define vii vector<ii>

vi vis, ts, scc;
vii switches;
vector<vi> adj, adjT;

void dfs1(int u){
    vis[u] = 1;
    for (auto v : adj[u])
        if (!vis[v]) dfs1(v);
    ts.push_back(u);
}

void dfs2(int u, int c){
    scc[u] = c;
    for (auto v : adjT[u])
        if (!scc[v]) dfs2(v, c);
}

signed main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n, m;
    cin >> n >> m;
    
    vi initial(n);
    vis = scc = vi(n);
    switches = vii(n, {-1,-1});
    adj = adjT = vector<vi>(2*n);

    for (int i = 0; i < n; i++) cin >> initial[i];
    for (int i = 0; i < m; i++){
        int qtd; cin >> qtd;
        // cout << "switches: ";
        while(qtd--){
            int s; cin >> s;
            s--;
            // cout << s << ' ' << switches[s].first << ' ' << switches[s].second << endl;
            if (switches[s].first == -1) switches[s].first = i;
            else switches[s].second = i;
        }
        // cout << endl;

    }

    for (int i = 0; i < n; i++){
        int a = switches[i].first;   
        int b = switches[i].second;
        // cout << initial[i] << ' ' << a << ' ' << b << endl;   
        if (initial[i] == 1){
            adj[a].push_back(b);
            adjT[b+n].push_back(a+n);
        }
        else {
            adj[a].push_back(b+n);
            adjT[b].push_back(a+n);
        }
    }

    for (int i = 0; i < n; i++)
        if (!vis[i]) dfs1(i);

    cout << "ts: ";
    for (auto x : ts) cout << x << ' ';
    cout << endl;

    int c = 1;
    for (int i = n-1; i >= 0; i--)
        if (!scc[ts[i]]) dfs2(i, c++);

    bool valid = true;
    for (int i = 0; i < m; i++){
        if (scc[i] != scc[i+n]) valid = false;
    }

    cout << (valid ? "YES" : "NO") << endl;

    return 0;
}