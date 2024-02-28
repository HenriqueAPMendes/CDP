#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define endl '\n'
#define ii pair<int,int>
#define vi vector<int>

#define INF 2123456789012345

int n, m, a, b, w;
vi d, p;
vector<vector<ii>> adj;

void belmann_ford(){
    for (int i = 2; i <= n; i++) d[i] = INF;
    d[1] = 0;
    for (int i = 1; i < n; i++)
        for (int u = 1; u <= n; u++)
            for (auto &[w,v] : adj[u]){
                if (d[v] > d[u]+w){
                    d[v] = d[u]+w;
                    p[v] = u;
                }
            }

}

void backtrack(int u, int s, bool firstIteration){
    if (u == s && !firstIteration) {cout << s << endl; return;}
    backtrack(p[u], s, false);
    cout << p[u] << ' ';
}

signed main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n >> m;
    d = p = vi(n+1);
    adj = vector<vector<ii>> (n+1);
    while(m--){
        cin >> a >> b >> w;
        adj[a].push_back({w,b});
    }

    belmann_ford();

    bool hasNegativeCycle = false;
    int first;
    for (int u = 1; u <= n; u++)
        for (auto &[w,v] : adj[u])
            if (d[v] > d[u]+w){
                hasNegativeCycle = true;
                first = u;
            }

    if (hasNegativeCycle) cout << "NO\n";
    else{
        backtrack(first, first, true);
    }

    return 0;
}