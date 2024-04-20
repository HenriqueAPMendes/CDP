#include <bits/stdc++.h>
using namespace std;

const int MAX = 312345;
const int INF = 312345;

vector<vector<int>> g(MAX);

int vertex(int node, int parent){
    
    if (g[node].size() == 1) return 1; // leaf node
    int ans = 0;
    for (int i = 0; i < (int)g[node].size(); i++)
        if (g[node][i] != parent)
            ans += vertex(g[node][i], node);

    return ans+1;
}

int minVertex(){
    int maxV = 0, x, totalSum = 0;
    for (int i = 0; i < (int)g[1].size(); i++){
        x = vertex(g[1][i],1);
        totalSum += x;
        maxV = max(maxV, x);
    }

    return totalSum-maxV;
    
}

int main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n, u, v;
    cin >> n;

    for (int i = 1; i <= n-1; i++){
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    if (g[1].size() <= 1) { cout << 1 << '\n'; return 0; }

    cout << minVertex()+1 << '\n';

    return 0;
}