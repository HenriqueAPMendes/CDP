#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define ii pair<int,int>
#define iii pair<int, ii>
#define vi vector<int>
#define MAX 212345
#define endl '\n'

vi _p(MAX), _rank(MAX);
int n, m;

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
        if (_rank[u]==_rank[v]) _rank[u]++;
    }
}

vector<iii> edges;
vector<iii> tree;
vi path;

iii kruskal(){
    iii last;
    for (int i = 1; i <= n; i++) {_p[i]=i; _rank[i]=0;}
    sort(edges.rbegin(), edges.rend());
    for (auto &[w,uv] : edges){
        int u = uv.first;
        int v = uv.second;
        if (_find(u) != _find(v)){
            tree.push_back({w,uv});
            _union(u,v);
        }
        else last = {w,uv};
    }
    return last;
}

void dfs(int u, int p, int end){
    path.push_back(u);
}

void solve(){
    cin >> n >> m;
    edges = vector<iii>(m);
    for(int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        edges[i] = {w, {u,v}};
    }
    iii ans = kruskal();
    dfs(ans.second.first, 0, ans.second.second)
    // cout << ans << endl;
}

signed main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int t; cin >> t;
    while(t--) solve();

    return 0;
}