#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ii pair<int,int>
#define vi vector<int>
#define vii vector<ii>
#define MAX 212345
#define endl '\n'

vector<vector<ii>> g(MAX);
map<string,int> s2u;
int n, m;

vi taken(MAX);

int prim(){
    priority_queue<ii> pq;
    taken[0] = 1;
    for (auto &v : g[0])
        if (!taken[v.second]) pq.push({-v.first, -v.second});  

    int cost = 0;
    while(!pq.empty()){
        ii front = pq.top(); pq.pop();
        int w = -front.first;
        int u = -front.second;
        if (!taken[u]) {
            cost += w;
            taken[u] = 1;
            for (auto &v : g[u])
                if (!taken[v.second]) pq.push({-v.first, -v.second});  
        }
    }
    return cost;
}

int main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    
    int t, first = 1;
    cin >> t;
    while(t--){
        int u, v, w, cnt = 0;
        string su, sv;
        cin >> n;
        cin >> m;
        for (int i = 0; i < m; i++){
            cin >> su >> sv >> w;
            if (s2u.find(su) == s2u.end()) s2u[su] = cnt++;
            if (s2u.find(sv) == s2u.end()) s2u[sv] = cnt++;
            u = s2u[su];
            v = s2u[sv];
            
            g[u].push_back({w,v});
            g[v].push_back({w,u});
        }

        for (int i = 0; i < n; i++) taken[i]=0;

        if (!first) cout << endl;
        cout << prim() << endl;
        
        for (int i = 0; i < n; i++) g[i].clear();
        s2u.clear();
        first = 0;
    }

    return 0;
}
