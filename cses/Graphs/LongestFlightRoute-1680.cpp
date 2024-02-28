#include <bits/stdc++.h>
using namespace std;

#define MAX 112345
#define INF 1123456789
#define endl '\n'
#define int long long int
#define vi vector<int>
#define ii pair<int, int>
 
int n, m, a, b;
vi d(MAX), vis(MAX), nxt(MAX);
vector<vi> adj(MAX);
 
void dfs(int node) {
    d[node] = (node == n ? 0 : -INF);
    for (int x : adj[node]) {
        if (!vis[x]) dfs(x);
        vis[x] = 1;
        if (d[x] >= d[node]) {
            d[node] = 1 + d[x];
            nxt[node] = x;
        }
    }
}
 
signed main () { 
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }

    dfs(1);
    if (d[1] < 0) cout << "IMPOSSIBLE" << endl;
    else {
        cout << d[1] + 1 << endl;
        cout << "1 ";
        int prox = nxt[1];
        while (prox) {
            cout << prox << ' ';
            prox = nxt[prox];
        }
        cout << endl;
    }
    return 0;
}