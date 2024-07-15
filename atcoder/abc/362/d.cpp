#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define endl '\n'
#define ii pair<int,int>
#define vi vector<int>
#define vii vector<ii>
#define vvi vector<vi>
#define vvii vector<vii>
#define INF 1123456789012345

vvii adj;
vi vis, d, a;
int n;

void dijkstra(int s){
    d[s] = 0;
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    pq.push({0, s});
    while(!pq.empty()){
        auto [dist,u] = pq.top();
        pq.pop();
        if (dist > d[u]) continue;
        for (auto [w, v] : adj[u]){
            if (u != 0) {
                if (d[v] > d[u] + w - a[u]){
                    d[v] = d[u]+w-a[u];
                    pq.push({d[v], v});
                }
            }
            else if (d[v] > d[u] + w){
                d[v] = d[u]+w;
                pq.push({d[v], v});
            }
        }
    }
}

void solve(){
    int n, m; cin >> n >> m;
    adj = vvii(n);
    d = vi(n, INF);
    vis = a = vi(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    while(m--){
        int u, v, b;
        cin >> u >> v >> b;
        u--, v--;
        adj[u].push_back({a[u]+b+a[v],v});
        adj[v].push_back({a[v]+b+a[u],u});
    }

    dijkstra(0);
    for (int i = 1; i < n; i++) cout << d[i] << ' '; cout << endl;
}

signed main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    solve();
    return 0;
}