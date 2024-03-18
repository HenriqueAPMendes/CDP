#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define endl '\n'
#define vi vector<int>
#define MAX 212345
#define INF 123456789012345


void solve(){
    int n, m;
    cin >> n >> m;
    vector<vi> adj(MAX+n);
    while(m--){
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back(c+n);
        adj[b].push_back(c+n);
        adj[c+n].push_back(a);
        adj[c+n].push_back(b);
    }
    int s, t;
    cin >> s >> t;
    vi dist(MAX+n, INF);
    dist[s] = 0;
    queue<int> q; q.push(s);
    while(!q.empty()){
        int u = q.front(); q.pop();
        for (auto v : adj[u]){
            if (dist[v] == INF) {
                dist[v] = dist[u]+1;
                q.push(v);
            }
        }
        
    }
    cout << dist[t]/2 << endl;
}

signed main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int t; cin >> t;
    while(t--) solve();

    return 0;
}