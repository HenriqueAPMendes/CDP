#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long int
#define vi vector<int>

signed main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    vector<vector<char>> board(8, vector<char>(8));


    int t; cin >> t;
    while(t--){

        for (int i = 0; i < 8; i++)
            for (int j = 0; j < 8; j++)
                cin >> board[i][j];

        int i, j;
        for(i = 0; i < 8; i++)
            for(j = 0; j < 8; j++)
                if (board[i][j] != '.') cout << board[i][j];
        cout << endl;
    }

    return 0;
}