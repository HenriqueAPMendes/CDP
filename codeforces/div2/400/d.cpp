#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define endl '\n'
#define vi vector<int>
#define ii pair<int,int>
#define vii vector<ii>

vi comp;
vii switches;
vector<vi> adj;

void dfs(int u, int c){
    comp[u] = c;
    for (auto v : adj[u])
        if (!comp[v]) dfs(v, c);
}
signed main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n, m;
    cin >> n >> m;
    
    vi initial(n);
    comp = vi(2*m);
    switches = vii(n, {-1,-1});
    adj = vector<vi>(2*m);

    for (int i = 0; i < n; i++) cin >> initial[i];
    
    for (int i = 0; i < m; i++){
        int qtd; cin >> qtd;
        while(qtd--){
            int s; cin >> s;
            s--;
            if (switches[s].first == -1) switches[s].first = i;
            else switches[s].second = i;
        }
    }

    // construir grafo de implicacoes
    for (int i = 0; i < n; i++){
        int a = switches[i].first;   
        int b = switches[i].second;
        if (initial[i] == 1){
            adj[a].push_back(b);
            adj[a+m].push_back(b+m);
            adj[b].push_back(a);
            adj[b+m].push_back(a+m);
        }
        else {
            adj[a].push_back(b+m);
            adj[a+m].push_back(b);
            adj[b+m].push_back(a);
            adj[b].push_back(a+m);
        }
    }

    for (int i = 0; i < 2*m; i++)
        if (!comp[i]) dfs(i, i+1);

    bool valid = true;
    for (int i = 0; i < m; i++)
        if (comp[i] == comp[i+m]) valid = false;
    

    cout << (valid ? "YES" : "NO") << endl;

    return 0;
}
