#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define vi vector<int>
#define endl '\n'

vector<vi> board, vis;
int n;

void dfs(int x, int y){
    if (vis[x][y]) return;
    if (board[x][y] == 1) return;
    vis[x][y] = 1;
    if (x < n-1) dfs(x+1, y);
    if (x > 0) dfs(x-1, y);
    if (y < n-1) dfs(x, y+1);
    if (y > 0) dfs(x, y-1);
}

void solve(){
    cin >> n;
    board = vector<vi>(n, vi(n));
    vis = vector<vi>(n, vi(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)  cin >> board[i][j];

    // checa se 0,0 se conecta com n-1,n-1
    dfs(0,0);
    cout << vis[n-1][n-1] << endl;
}

signed main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int t; cin >> t;
    while(t--) solve();

    return 0;
}