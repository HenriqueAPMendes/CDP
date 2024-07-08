#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long int
#define vi vector<int>
#define ii pair<int,int>
#define vii vector<ii>
#define INF 1123456789012345

vector<vii> adj;
vi d;

void dijkstra(int s){
    d[s] = 0;
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    pq.push({0, s});
    while(!pq.empty()){
        auto [dist,u] = pq.top();
        pq.pop();
        if (dist > d[u]) continue;
        for (auto [w, v] : adj[u]){
            if (d[v] > d[u] + w){
                d[v] = d[u] + w;
                pq.push({d[v], v});
            }
        }
    }
}

void solve(){
    int n, m; 
    cin >> n >> m;
    adj = vector<vii> (2*n);
    d = vi(2*n, INF);
    while(m--){
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        adj[a].push_back({c,b});
        adj[a].push_back({c/2, b+n});
        adj[a+n].push_back({c, b+n});

        // cout << a << ' ' << b << ' ' << c << endl;
        // cout << a << ' ' << b+n << ' ' << c/2 << endl;
    }



    dijkstra(0);
    cout << d[2*n-1] << endl;

}

signed main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    solve();
    return 0;
}
