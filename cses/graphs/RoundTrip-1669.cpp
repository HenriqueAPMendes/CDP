#include <bits/stdc++.h>
using namespace std;

#define MAX 212345
#define CYCLE -1

vector<vector<int>> g(MAX);
vector<int> vis(MAX), p(MAX);
bool found = true;

void printP(int u){
    int s = u;
    found = false;
    stack<int> st;
    st.push(u);
    vis[u] = CYCLE;
    u = p[u];
    
    while(vis[u] != CYCLE){
        vis[u] = CYCLE;
        st.push(u);
        u = p[u];
    }
    st.push(s);
    cout << st.size() << endl;
    while (!st.empty()) {
        cout << st.top() << ' ';
        st.pop();
    }
    cout << endl;
}

void dfs(int u, int val){
    if (vis[u]) return;
    vis[u] = val;
    for (auto &v : g[u]){
        if (vis[v] && abs(vis[v]-vis[u]) > 1){
            p[v] = u;
            if (found) printP(v);
        }
        if (!vis[v]){
            p[v]=u;
            dfs(v, val+1);
        }
    }
}

void solve(int n){
    for (int i = 1; i <= n; i++)
        if (!vis[i]) 
            dfs(i, 1);
    

    if (found) cout << "IMPOSSIBLE\n";
}

int main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n, m;
    cin >> n >> m;
    while(m--){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    solve(n);

    return 0;
}