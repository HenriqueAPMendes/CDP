#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
const int P = 1e9 + 7;


int main(){
    int n; cin >> n;
    
    vector<vi> board(n, vi(n)), memo(n, vi(n));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++){
            char c; cin >> c;
            if (c == '*') board[i][j] = 1;
        }
    

    memo[0][0] = !board[0][0];
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (board[i][j]) continue;
            if (i > 0) memo[i][j] += memo[i-1][j], memo[i][j] %= P;
            if (j > 0) memo[i][j] += memo[i][j-1], memo[i][j] %= P;
        }
    }

    cout << memo[n-1][n-1] << endl;


    return 0;
}