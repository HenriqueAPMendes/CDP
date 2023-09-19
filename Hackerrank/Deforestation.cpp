#include <bits/stdc++.h>
using namespace std;

#define MAX 512

// terminar

vector<int> adj(MAX);
int vis[MAX];

int grundy(int u){
    vis[u] = 1;
    int ans = 0;
    for (int v : adj[u])
        if (vis[v]) ans ^= grundy(v) + 1;
    return ans;
}

int main(){
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        for (int u = 0; u < n; u++) adj[u].clear();
        for (int i = 0; i < n-1;i++){
            int u, v;
            cin >> u >> v;
            u--; v--;
            adj[u].push_back(v); adj[v].push_back[u];
        }
        // mais algo aqui
    }
    // mais algo aqui
}