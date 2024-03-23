#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define endl '\n'
#define vi vector<int>
#define ii pair<int,int>
#define vii vector<ii>
#define INF 1123456789012345

ii lastvisited;

void dfs(ii u, vector<vi> vis, vector<vi> salao, int l, int c){
    int i = u.first;
    int j = u.second;
    if (vis[i][j]) return;
    vis[i][j] = 1;
    lastvisited = {i,j};

    if (i > 0 && !vis[i-1][j] && salao[i-1][j] == 1) dfs({i-1,j}, vis, salao, l, c);
    if (i < l-1 && !vis[i+1][j] && salao[i+1][j] == 1) dfs({i+1,j}, vis, salao, l, c);
    if (j > 0 && !vis[i][j-1] && salao[i][j-1] == 1) dfs({i,j-1}, vis, salao, l, c);
    if (j < c-1 && !vis[i][j+1] && salao[i][j+1] == 1) dfs({i,j+1}, vis, salao, l, c);
}

signed main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int l, c, si, sj;
    cin >> l >> c;
    cin >> si >> sj;
    si--; sj--;
    vector<vi> salao(l, vi(c)), vis(l, vi(c));
    for (int i = 0; i < l; i++)
        for (int j = 0; j < c; j++)
            cin >> salao[i][j];

    lastvisited = {si,sj};

    dfs(lastvisited, vis, salao, l, c);

    cout << lastvisited.first+1 << ' ' << lastvisited.second+1 << endl;

    return 0;
}