#include <bits/stdc++.h>
using namespace std;

#define MAX 512
#define INF 1123456789012345

#define int long long

int n, m, q;

vector<vector<int>> adj(MAX, vector<int>(MAX, INF));

void floyd_warshall(){
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                adj[i][j] = min(adj[i][j], adj[i][k]+adj[k][j]);
    
}

signed main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n >> m >> q;
    while(m--){
        int a, b, c;
        cin >> a >> b >> c;
        adj[a][b] = adj[b][a] = min(adj[a][b], c);
    }

    for (int i = 1; i <= n; i++) adj[i][i] = 0;

    floyd_warshall();

    while(q--){
        int a, b;
        cin >> a >> b;
        cout << (adj[a][b] == INF ? -1 : adj[a][b]) << endl;
    }

    return 0;
}