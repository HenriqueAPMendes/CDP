#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ii pair<int,int>
#define vi vector<int>
#define vii vector<ii>

#define MAX 212345
#define endl '\n'

vector<pair<int,ii>> edges;
vi _p(MAX);
vi _rank(MAX);
map<string,int> s2u;
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
        if (_rank[u] == _rank[v]) _rank[u]++;
    }
}

int kruskal(){
    int cost = 0, u, v, w;
    for (int i = 0; i < n; i++) {_p[i]=i; _rank[i]=0;}
    sort(edges.begin(), edges.end());
    for (auto &e : edges){
        u = e.second.first;
        v = e.second.second;
        w = e.first;
        if (_find(u) != _find(v)){
            cost += w;
            _union(u, v);
        }
    }
    return cost;
}

int main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    
    int t, first = 1;
    cin >> t;
    while(t--){
        int u, v, w, cnt = 0;
        string su, sv;
        cin >> n;
        cin >> m;
        for (int i = 0; i < m; i++){
            cin >> su >> sv >> w;
            if (s2u.find(su) == s2u.end()) s2u[su] = cnt++;
            if (s2u.find(sv) == s2u.end()) s2u[sv] = cnt++;
            u = s2u[su];
            v = s2u[sv];
            
            edges.push_back({w,{u,v}});
        }

        if (!first) cout << endl;
        cout << kruskal() << endl;
        
        edges.clear();
        s2u.clear();
        first = 0;
    }

    return 0;
}