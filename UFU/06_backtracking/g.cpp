#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define vi vector<int>
#define endl '\n'
#define ii pair<int,int>
#define INF 1234567890123456

vector<vi> board, dist, vis;
int l, c;

void bfs(ii s){
    dist[s.first][s.second] = 0;
    queue<ii> q; q.push(s);
    while(!q.empty()){
        ii u = q.front(); q.pop();
        int x = u.second;
        int y = u.first;
        vis[y][x] = 1;
        
        if (x+1 < c && !vis[y][x+1] && board[y][x+1]) {dist[y][x+1] = dist[y][x]+1; q.push({y, x+1});}
        if (x-1 >= 0 && !vis[y][x-1] && board[y][x-1]) {dist[y][x-1] = dist[y][x]+1; q.push({y, x-1});}
        if (y+1 < l && !vis[y+1][x] && board[y+1][x]) {dist[y+1][x] = dist[y][x]+1; q.push({y+1, x});}
        if (y-1 >= 0 && !vis[y-1][x] && board[y-1][x]) {dist[y-1][x] = dist[y][x]+1; q.push({y-1, x});}
    }
}

signed main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> l >> c;
    board = vis = vector<vi>(l, vi(c));
    dist = vector<vi>(l, vi(c, INF));
    for (int i = 0; i < l; i++)
        for (int j = 0; j < c; j++) cin >> board[i][j];

    ii start, end;
    for (int i = 0; i < l; i++)
        for (int j = 0; j < c; j++){
            if (board[i][j] == 2) start = {i,j};
            if (board[i][j] == 3) end = {i,j};
        }
    
    bfs(start);
    cout << dist[end.first][end.second]+1 << endl;

    // bfs

    

    return 0;
}