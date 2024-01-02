#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define MAX 112345

vector<vector<int>> g(MAX);
vector<int> vis(MAX,0);
vector<int> rep(MAX);

int visit(int n){
    int ans = 0;
    bool used = false;
    for (int i = 1; i <= n; i++) {
        used = false;
        queue<int> q;
        if (!vis[i]) q.push(i);
        while(!q.empty()){
            int u = q.front(); q.pop();
            vis[u] = ans+1;
            rep[ans+1] = u; // representante da componente
            used = true;
            for (auto &x : g[u])
                if (!vis[x]) q.push(x);
        }
        if (used) ans++;
    }
    return ans;
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n, m;
    cin >> n >> m;
    
    int u,v;
    for (int i = 0; i < m; i++){
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    int ans = visit(n)-1;
    cout << ans << endl;
    for(int i = 1; i <= ans; i++)
        cout << rep[i] << ' ' << rep[i+1] << endl;
    

    return 0;
}