#include <bits/stdc++.h>
using namespace std;

const int MAX = 112;
const int INF = 112345678;
int n,m,l, dist[MAX][MAX][MAX];

vector<vector<vector<int>>> dist(MAX, vector<vector<int>>(MAX, vector<int>(MAX,INF)));

struct Point{
    int x; int y; int z;
    Point() {}
    Point(int _x, int _y, int _z) : x(_x), y(_y), z(_z) {}
};

void bfs(Point start){
    Point p = start;
    queue<Point> q;
    
    dist[p.x][p.y][p.z] = 0;
    q.push(p);
    
    while(!q.empty()){
        p = q.front();
        q.pop();
    }
}

int main (){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n >> m >> l;

    Point start, dest;
    cin >> start.x >> start.y >> start.z;
    cin >> dest.x >> dest.y >> dest.z;

    bfs(start);
    cout << dist[dest.x][dest.y][dest.z] << '\n';

    return 0;
}