#include <bits/stdc++.h>
using namespace std;

#define MAX 112345
#define INF 1123456

vector<vector<int>>g (MAX);
vector<int> color(MAX, INF);

bool bfs(int s){
    color[s]=0;
    bool isBipartite = true;
    queue<int> q; q.push(s);
    while(!q.empty() && isBipartite){
        int u = q.front(); q.pop();
        for (auto &v : g[u]){
            if (color[v] == INF){
                color[v] = 1-color[u];
                q.push(v);
            }
            else if (color[v] == color[u]){
                isBipartite = false; break;
            }
        }
    }
    return isBipartite;
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

    bool possible = true;
    for (int i = 1; i <= n; i++){
        if (color[i] == INF)
            possible &= bfs(i);
    }
    if (!possible) cout << "IMPOSSIBLE\n";
    else{
        for (int i = 1; i <= n; i++) cout << color[i]+1 << ' ';
        cout << endl;
    }

    return 0;
}