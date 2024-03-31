#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define endl '\n'
#define ii pair<int,int>
#define vii vector<ii>

#define PLUS 1
#define MINUS 2

int n, m;
vector<vi> adj, adjT;
vi comp, vis, ts;

void dfs1(int u){
    vis[u] = 1;
    for (auto v : adj[u])
        if (!vis[v]) dfs1(v);
    ts.push_back(u);
}

void dfs2(int u, int c){
    comp[u] = c;
    for (auto v : adjT[u])
        if (!comp[v]) dfs2(v, c);
}

int main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n >> m;
    adj = adjT = vector<vi>(2*m);
    comp = vis = vi(2*m);

    for (int i = 0; i < n; i++){
        char s1, s2;
        int t1, t2;
        cin >> s1 >> t1 >> s2 >> t2;
        t1--; t2--;
        if (s1 == '+' && s2 == '+'){
            adj[t1+m].push_back(t2);
            adj[t2+m].push_back(t1);
            adjT[t2].push_back(t1+m);
            adjT[t1].push_back(t2+m);
        }
        else if (s1 == '-' && s2 == '+'){
            adj[t1].push_back(t2);
            adj[t2+m].push_back(t1+m);
            adjT[t2].push_back(t1);
            adjT[t1+m].push_back(t2+m);
        }
        else if (s1 == '+' && s2 == '-'){
            adj[t1+m].push_back(t2+m);
            adj[t2].push_back(t1);
            adjT[t1].push_back(t2);
            adjT[t2+m].push_back(t1+m);
        }
        else { // - -
            adj[t1].push_back(t2+m);
            adj[t2].push_back(t1+m);
            adjT[t2+m].push_back(t1);
            adjT[t1+m].push_back(t2);
        }
    }

    for (int i = 0; i < 2*m; i++)
        if (!vis[i]) dfs1(i);

    reverse(ts.begin(), ts.end());
    int c = 0;
    for (auto u : ts)
        if (!comp[u]) dfs2(u, ++c);
    
    bool ok = true;
    vi ans(m);
    for (int i = 0; i < m; i++){
        if (comp[i] == comp[i+m]) ok = false;
        ans[i] = (comp[i] > comp[i+m] ? 1 : 0);
    }
    
    if (!ok) { cout << "IMPOSSIBLE" << endl; return 0; }

    for (int i = 0; i < m; i++)
        cout << (ans[i] == 1 ? "+ " : "- ");
    cout << endl;
    

    return 0;
}