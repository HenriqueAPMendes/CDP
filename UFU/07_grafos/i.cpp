#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define endl '\n'
#define vi vector<int>
#define ii pair<int,int>

vector<vi> board;
int n, m;

void dfs(ii s){
    int i = s.first;
    int j = s.second;
    board[i][j] = 2;
    if (i > 0 && board[i-1][j] == 1) dfs({i-1,j});
    if (i < n-1 && board[i+1][j] == 1) dfs({i+1,j});
    if (j > 0 && board[i][j-1] == 1) dfs({i,j-1});
    if (j < m-1 && board[i][j+1] == 1) dfs({i,j+1});
}

void solve(){
    board = vector<vi>(n, vi(m));
    vector<ii> leaks;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            char c; cin >> c;
            if (c == 'A') board[i][j] = 1;
            if (c == 'T') {board[i][j] = 2; leaks.push_back({i,j});}
            if (c == 'X') board[i][j] = 3;
        }
    }

    for (auto p : leaks) dfs(p);

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (board[i][j] == 1) cout << 'A';
            if (board[i][j] == 2) cout << 'T';
            if (board[i][j] == 3) cout << 'X';
        }
        cout << endl;
    }
    cout << endl;
}

signed main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n >> m;
    while(1){
        // cout << n << ' ' << m << endl;
        if (n == 0 && m == 0) break;
        solve();
        cin >> n >> m;
    }

    return 0;
}