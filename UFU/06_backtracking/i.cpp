#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define vi vector<int>
#define endl '\n'
#define ii pair<int,int>
#define INF 1234567898679

int minPassos = 123456789023;
vector<vi> vis(8, vi(8,0)), dist(8, vi(8,INF));

void bfs(ii s){
    dist[s.first][s.second] = 0;
    queue<ii> q; q.push(s);
    while(!q.empty()){
        ii u = q.front(); q.pop();
        int x = u.second;
        int y = u.first;
        vis[y][x] = 1;
        
        if (x+1 < 8 && y+2 < 8 && !vis[y+2][x+1]) {dist[y+2][x+1] = dist[y][x]+1; q.push({y+2, x+1});}
        if (x+1 < 8 && y-2 >= 0 && !vis[y-2][x+1]) {dist[y-2][x+1] = dist[y][x]+1; q.push({y-2, x+1});}
        if (x-1 >= 0 && y+2 < 8 && !vis[y+2][x-1]) {dist[y+2][x-1] = dist[y][x]+1; q.push({y+2, x-1});}
        if (x-1 >= 0 && y-2 >= 0 && !vis[y-2][x-1]) {dist[y-2][x-1] = dist[y][x]+1; q.push({y-2, x-1});}
        if (x+2 < 8 && y+1 < 8 && !vis[y+1][x+2]) {dist[y+1][x+2] = dist[y][x]+1; q.push({y+1, x+2});}
        if (x+2 < 8 && y-1 >= 0 && !vis[y-1][x+2]) {dist[y-1][x+2] = dist[y][x]+1; q.push({y-1, x+2});}
        if (x-2 >= 0 && y+1 < 8 && !vis[y+1][x-2]) {dist[y+1][x-2] = dist[y][x]+1; q.push({y+1, x-2});}
        if (x-2 >= 0 && y-1 >= 0 && !vis[y-1][x-2]) {dist[y-1][x-2] = dist[y][x]+1; q.push({y-1, x-2});}
    }
}


signed main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    string start, end;
    cin >> start >> end;
    int x0, y0, x1, y1;
    x0 = (start[0] - 'a');
    y0 = start[1] - '0' - 1;
    x1 = (end[0] - 'a');
    y1 = end[1] - '0' - 1;

    bfs({y0,x0});

    cout << dist[y1][x1] << endl;
    return 0;
}