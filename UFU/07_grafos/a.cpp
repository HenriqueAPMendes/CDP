#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define endl '\n'
#define vi vector<int>
#define ii pair<int,int>

#define MAX 512
#define INF 1234567654321234

int res[MAX][MAX], mf, f, s, t;
vi p;

void augment(int v, int minEdge) {
    if (v == s) {f = minEdge; return; }
    if (p[v] != -1){
        augment(p[v], min(minEdge, res[p[v]][v]));
        res[p[v]][v] -= f;
        res[v][p[v]] += f;
    }
}

signed main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    // set res, s, t
    int n, m;
    cin >> n >> m;
    while(m--){
        int x, y, p;
        cin >> x >> y >> p;
        res[x][y] = p;
    }
    s = 1;
    t = n;
    mf = 0;
    while(1){
        f = 0;
        vi dist(MAX, INF); dist[s] = 0;
        queue<int> q; q.push(s);
        p.assign(MAX, -1);
        while(!q.empty()){
            int u = q.front(); q.pop();
            if (u == t) break;
            for (int v = 0; v < MAX; v++)
                if (res[u][v] > 0 && dist[v] == INF)
                    dist[v] = dist[u] + 1, q.push(s), p[v] = u;
        }
        augment(t, INF);
        if (f == 0) break;
        mf += f;
    }
    cout << mf << endl;

    return 0;
}