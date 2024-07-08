#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long int
#define vi vector<int>
#define ii pair<int,int>
#define vii vector<ii>
#define INF 1123456789012345

vector<vii> adj;
vi d, p;
int n;

void backtrack(int u, int start){
    if (p[u] == start) return;
    backtrack(p[u], start);
    cout << u+1 << ' ';
}

void bf(int s){
    d[s] = 0;
    for (int i = 0; i < n; i++)
        for (int u = 0; u < n; u++)
            for (auto [w,v] : adj[u]){
                if (d[v] > d[u]+w){
                    d[v] = d[u]+w;
                    p[v] = u;
                }
            }
}

void solve(){
    int m; cin >> n >> m;
    d = vi(n, INF);
    p = vi(n);
    adj = vector<vii> (n);
    while(m--){
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        adj[a].push_back({c, b});
    }

    bf(0);
    bool hasNeg = false;
    int start;
    for (int u = 0; u < n; u++)
        for (auto [w,v]: adj[u])
            if (d[v] > d[u]+w)
                hasNeg = true, start = v;

    if (!hasNeg) { cout << "NO" << endl; return; }
    cout << "YES" << endl;
    cout << start << endl;
    for (auto x : p) cout << x << ' '; cout << endl;
    backtrack(start, start);

}

signed main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    solve();
    return 0;
}
