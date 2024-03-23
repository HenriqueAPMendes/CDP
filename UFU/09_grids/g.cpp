#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define endl '\n'
#define vi vector<int>
#define ii pair<int,int>
#define vii vector<ii>
#define INF 1123456789012345

int mat[5][5], vis[5][5];

void dfs(ii u){
    int i = u.first;
    int j = u.second;
    // cout << i << ' ' << j << endl;
    if (vis[i][j]) return;
    vis[i][j] = 1;

    if (i > 0 && !vis[i-1][j] && mat[i-1][j] != 1) dfs({i-1,j});
    if (i < 4 && !vis[i+1][j] && mat[i+1][j] != 1) dfs({i+1,j});
    if (j > 0 && !vis[i][j-1] && mat[i][j-1] != 1) dfs({i,j-1});
    if (j < 4 && !vis[i][j+1] && mat[i][j+1] != 1) dfs({i,j+1});
}

void solve(){
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            vis[i][j] = 0;

    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            cin >> mat[i][j];

    dfs({0,0});

    cout << vis[4][4] << endl;        
}

signed main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int t; cin >> t;
    while(t--) solve();

    return 0;
}