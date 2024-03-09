#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define endl '\n'
#define vi vector<char>
#define ii pair<int,int>

void solve(){
    int n, m; cin >> n >> m;
    vector<vi> board(n, vi(m));
    queue<ii> q;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++){
            cin >> board[i][j];
            if(board[i][j] == 'o')
                q.push({i, j});
        }
    
    while(!q.empty()){
        ii u = q.front(); q.pop();
        int i = u.first;
        int j = u.second;
        if(i+1 < n && board[i+1][j] == '.'){
            board[i+1][j] = 'o'; 
            q.push({i+1, j});
        }
        else if (i+1 < n){
            if (board[i+1][j] == '#'){
                if(j-1 >= 0 && board[i][j-1] == '.'){
                    board[i][j-1]='o'; 
                    q.push({i, j-1});
                }
                if(j+1 >= 0 && board[i][j+1] == '.'){
                    board[i][j+1]='o'; 
                    q.push({i, j+1});
                }
            }
        }   
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout<<board[i][j];
        } cout<<endl;
    }
}

signed main (){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    solve();

    return 0;
}