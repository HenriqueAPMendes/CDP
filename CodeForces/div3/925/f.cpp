#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define vi vector<int>
#define ii pair<int,int>
#define iii pair<int,ii>
#define endl '\n'

vector<vi> adj;
vi vis;
int n;
vi ts;
vector<ii> conditions;


void dfs(int u){
    if(vis[u]) return;
    vis[u] = 1;
    for (auto &v : adj[u])
        if (!vis[v]) dfs(v);
    
    ts.push_back(u);
}

bool topological_sort(){
    ts.clear();

    for (int i = 1; i <= n; i++)
        dfs(i);
    
    for (auto &x : ts) cout  << x << ' '; cout << endl;
    reverse(ts.begin(), ts.end());
    vi priority(n+1);
    cout << ts.size() << ' ' << n << endl;
    // for (int i = 0; i < ts.size(); i++) priority[ts[i]] = i;
    
    for (auto &[f,s] : conditions)
        if (priority[f] > priority[s]) return false;
    
    return true;
}


void solve(){
    int k;
    cin >> n >> k;
    
    vi a(n);
    vis = vi(n+1);
    adj = vector<vi>(n+1);
    
    for (int i = 0; i < k; i++){
        for (int j = 0; j < n; j++) cin >> a[i];

        for (int j = 1; j < n-2; j++) {

            adj[a[i]].push_back(a[i+1]);
            conditions.push_back({a[i], a[i+1]});
        }
    }

    bool valid = topological_sort();
    cout << (valid ? "YES" : "NO") << endl;
}

signed main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int t; cin >> t;
    while(t--) solve();

    return 0;
}