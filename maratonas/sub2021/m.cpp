#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define endl '\n'
#define vi vector<int>
#define ii pair<int,int>
#define vii vector<ii>
#define vvi vector<vi>
#define MAXN 112345

int nextId = 2;
vvi adj(MAXN);
vi dead(MAXN);
queue<int> succession;

void dfs(int node){
    succession.push(node);
    for (auto son : adj[node])
        dfs(son);
}

void solve() {
    int q;
    cin >> q;
    vi queries;
    while (q--){
        int a, b;
        cin >> a >> b;
        if (a == 1)
            adj[b].push_back(nextId++);
        else
            queries.push_back(b);
    }
    dfs(1);
    for (auto node : queries){
        dead[node] = 1;
        while (dead[succession.front()])
        succession.pop();
        cout << succession.front() << endl;
    }
}

signed main(){
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}