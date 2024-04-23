#include <bits/stdc++.h>
using namespace std;

#define MAX 212345
#define INF 2123456789012345

#define int long long

#define ii pair<int,int>

vector<vector<ii>> adj(MAX);
vector<int> dist(MAX);

int n, m;

void dijkstra(int s){
    int d, u, v;
    for (int i = 1; i <= n; i++) dist[i] = INF;
    dist[s] = 0;
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    pq.push({0,s});
    while(!pq.empty()){
        d = pq.top().first;
        u = pq.top().second;
        pq.pop();
        if (d > dist[u]) continue;

        for (auto &x : adj[u]){
            d = x.first;
            v = x.second;
            if (dist[v] > dist[u] + d){
                dist[v] = dist[u] + d;
                pq.push({dist[v], v});
            }
        }
    }
}

signed main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n >> m;
    while(m--){
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({c, b});
    }

    dijkstra(1);

    for (int i = 1; i <= n; i++) cout << dist[i] << ' '; cout << endl;

    return 0;
}