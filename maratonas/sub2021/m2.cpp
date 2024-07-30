#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define endl '\n'
#define vi vector<int>
#define ii pair<int,int>
#define vii vector<ii>
#define vvi vector<vi>
#define vvii vector<vii>

#define MAX 300000

vvi g(MAX);
vi alive(MAX);

void dfs(vvi &g, vi &alive, int node, vi &visited, int &cur_king, int initial_king){
    if(initial_king != cur_king) return;    
    if(alive[node]) {cur_king = node; return;} 
    visited[node] = true;
    
    for(auto &v: g[node]){
        if(initial_king != cur_king){return;} 
        if(!visited[v]){   
            dfs(g, alive, v, visited, cur_king, initial_king);
        }
    }
}

void solve(){
    int q; cin >> q; 
    int cur_king = 1; int next = 2;
    alive[1] = 1;
    queue<int> current_sequence; current_sequence.push(1);

    while(q-->0){
        int type, node; cin >> type >> node;

        if(type == 1){
            g[node].push_back(next);
            alive[next++] = 1;
        } else {    
            alive[node] = 0;
            if(node == cur_king){
                vi visited(MAX);
                dfs(g, alive, node, visited, cur_king, cur_king);
            }
            cout << cur_king << endl;
        }
    }

}

int main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    solve();

    return 0;
}