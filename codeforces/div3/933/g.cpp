#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define endl '\n'
#define vi vector<int>
#define INF 123456789012345

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vi> g(n+m+1);
    map<int, int> color;
    int curr = n + 1;
    for (int i = 0; i < m;i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (color[c] == 0)
            color[c] = curr++;
        
        c = color[c];
        g[a].push_back(c);
        g[b].push_back(c);
        g[c].push_back(a);
        g[c].push_back(b);
    }

    int s, t;
    cin >> s >> t;

    queue<int> q;
    q.push(s);
    vi d(n+m+1, INF);
    d[s] = 0;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (auto v : g[u]) {
            if (d[v] == INF) {
                q.push(v);
                d[v] = d[u] + 1;
            }
        }
 
    }
    cout << d[t] / 2 << endl;
 
 
 
}

signed main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int t; cin >> t;
    while(t--) solve();

    return 0;
}