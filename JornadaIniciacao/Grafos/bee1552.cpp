#include <bits/stdc++.h>
using namespace std;

#define MAX 512
#define vi vector<int>
#define ii pair<int,int>
#define vii vector<ii>

vi taken(MAX);
vii grid(MAX);
vector<vector<pair<double,int>>> g(MAX);

double prim(){
    priority_queue<pair<double,int>> pq;
    taken[0] = 1;
    for (auto& v: g[0])
        if (!taken[v.second]) pq.push({-v.first, -v.second});

    double cost = 0;
    while(!pq.empty()){
        pair<double,int> front = pq.top(); pq.pop();
        double w = -front.first;
        int u = -front.second;
        if (!taken[u]){
            cost += w;
            taken[u] = 1;
            for (auto &v : g[u])
                if (!taken[v.second]) pq.push({-v.first, -v.second});
        }
    }
    return cost;
}

int main(){
    int c, n, x, y;
    scanf("%d",&c);
    while(c--){
        scanf("%d", &n);
        for (int i = 0; i < n; i++){
            scanf("%d %d", &x, &y);
            grid[i] = {x,y};   
        }
        for (int i = 0; i < n; i++){
            for (int j = i+1; j < n; j++){
                int dy = grid[j].second - grid[i].second;
                int dx = grid[j].first - grid[i].first;
                double w = sqrt(dx*dx + dy*dy);
                g[i].push_back({w,j});
                g[j].push_back({w,i});
            }
        }
        // for (int i = 0; i < n; i++){
        //     cout << i << endl;
        //     for (auto &e : g[i])
        //         cout << e.first << ' ' << e.second << endl;
        // }
        double cost = prim();
        printf("%.2f\n", cost/100);

        for (int i = 0; i < n; i++){taken[i]=0; g[i].clear();}
    }
}