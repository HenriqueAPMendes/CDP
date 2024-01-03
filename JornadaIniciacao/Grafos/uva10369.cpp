#include<bits/stdc++.h>
using namespace std;

#define ii pair<int,int>
#define MAX 1123
#define vi vector<int>
#define vii vector<ii>
#define viii vector<vii>
#define endl '\n'

vii grid(MAX);
vector<pair<double,ii>> edges;

vi _p(MAX);
vi _rank(MAX);

int _find(int u){
    if (_p[u] == u) return u;
    return _p[u] = _find(_p[u]);
}

void _union(int u, int v){
    u = _find(u);
    v = _find(v);
    if (_rank[u] < _rank[v]) _p[u]=v;
    else{
        _p[v]=u;
        if (_rank[u] == _rank[v]) _rank[u]++;
    }
}

pair<double,double> kruskal(int n){
    int u, v;
    double cost = 0, w, maxW = 0;
    for (int i = 0; i < n; i++) {_p[i]=i; _rank[i]=0;}
    for (auto &e : edges){
        u = e.second.first;
        v = e.second.second;
        w = e.first;
        if (_find(u) != _find(v)){
            cost += w;
            // cout << w << endl;
            maxW = max(maxW,w);
            _union(u,v);
        }
    }
    return {cost,maxW};
}

int main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int t;
    cin >> t;
    while(t--){
        int s, p, x, y;
        cin >> s >> p;
        for (int i = 0; i < p; i++){
            cin >> x >> y;
            grid[i] = {x,y};
        }
        for (int i = 0; i < p; i++){
            for (int j = i+1; j < p; j++){
                int dy = grid[j].second - grid[i].second;
                int dx = grid[j].first - grid[i].first;
                double w = sqrt(dx*dx + dy*dy);
                edges.push_back({w, {i,j}});
            }
        }


        sort(edges.begin(), edges.end());
        
        for (auto e : edges){
            cout << e.first << ' ' << e.second.first << ' ' << e.second.second << endl;
        }
        cout << endl;

        int to_remove = s*(s-1)/2; // pode estar errado
        edges.erase(edges.end()-to_remove, edges.end());

        for (auto e : edges){
            cout << e.first << ' ' << e.second.first << ' ' << e.second.second << endl;
        }
        cout << endl;

        cout << kruskal(p).second << endl;
        edges.clear();

    }

    return 0;
}