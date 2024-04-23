#include <bits/stdc++.h>
using namespace std;

#define MAX 112345
#define INF 1123456

vector<vector<int>> g(MAX);
vector<int> d(MAX, INF), p(MAX);

void printPath(int n){
    if (n == 1) {cout << 1 << ' '; return;}
    printPath(p[n]);
    cout << n << ' ';
}

void bfs(int s){
    d[s] = 0;
    queue<int> q; q.push(s);
    while(!q.empty()){
        int u = q.front(); q.pop();
        for (auto &v : g[u]){
            if (d[v] == INF){
                d[v] = d[u]+1;
                p[v] = u;
                q.push(v);
            }
        }
    }
}

int main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n,m;
    cin >> n >> m;
    while(m--){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    bfs(1);

    if (d[n] == INF) cout << "IMPOSSIBLE\n";
    else{
        cout << d[n]+1 << endl;
        printPath(n);
        cout << endl;
    }

    return 0;
}