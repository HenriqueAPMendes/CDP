#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define endl '\n'
#define vi vector<int>
#define ii pair<int,int>
#define iii tuple<int, int, int>

vector<iii> edges, existing_edges;
int n;
vi _p, _rank;

// MUF
int _find(int u){
    if (_p[u] == u) return u;
    return _p[u] = _find(_p[u]);
}

void _union(int u, int v){
    u = _find(u);
    v = _find(v);
    if (_rank[u] < _rank[v]) _p[u] = v;
    else{
        _p[v] = u;
        if (_rank[u] == _rank[v]) _rank[u]++;
    }
}


int kruskal(){
    int cost = 0;
    sort(edges.begin(), edges.end());
    for (auto &[w, u, v] : edges){
        if (_find(u) != _find(v)){
            cost += w;
            _union(u, v);
        } 
    }
    return cost;
}

void solve(){
    int n; cin >> n;
    _p = _rank = vi(n);
    vector<vi> m(n, vi(n));
    vi remove(n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> m[i][j];  

    for (int i = 1; i < n; i++)
        for (int j = 0; j < i; j++){
            if (m[i][j]) existing_edges.push_back({m[j][i], i, j});
            else edges.push_back({m[j][i], i, j});
        }

    for(int i = 0; i < n; i++) {_p[i]=i; _rank[i]=0;}
    // unite existing edges and run kruskal
    for (auto &[w,u,v] : existing_edges){
        _union(u,v);     
    }
    // run kruskal without any removal
    int ans = kruskal();
    cout << ans << endl;

    // run kruskal to see wether the edges should be removed or not
    for (int i = 0; i < (int)existing_edges.size(); i++){
        for(int i = 0; i < n; i++) {_p[i]=i; _rank[i]=0;}
        for (int j = 0; j < (int)existing_edges.size(); j++){
            if (i == j || remove[i]) continue;
            auto [w,u,v] = existing_edges[i];
            _union(u,v);     
        }

        int cost = kruskal();
        cout << cost << endl;
        if (cost < ans){
            ans = cost;
            remove[i] = 1;
        }
    }
    cout << ans << endl;
}

signed main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    solve();
    return 0;
}