#include <bits/stdc++.h>
using namespace std;

int board[8][8];
vector<int> row(8,0);
vector<int> ld(15,0);
vector<int> rd(15,0);

int ans;

void place(int c){
    if (c == 8) {ans++; return;}
    for (int i = 0; i < 8; i++){
        if (!row[i] and !ld[i+c] and !rd[c-i+7] and !board[i][c]){
            row[i]=1;
            ld[i+c]=1;
            rd[c-i+7]=1;
            place(c+1);
            rd[c-i+7]=0;
            ld[i+c]=0;
            row[i]=0;
        }
    }
}

void solve(){
    int c = 0;
    for (int i = 0; i < 8; i++){
        if (!board[i][c]){
            row[i]=1;
            ld[i+c]=1;
            rd[c-i+7]=1;
            place(c+1);
            rd[c-i+7]=0;
            ld[i+c]=0;
            row[i]=0;
        }
    }
}

int main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    char c;

    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++){
            cin >> c;
            board[i][j] = (c == '*') ? 1 : 0;
        }

    ans = 0;

    solve();

    cout << ans << endl;

    return 0;
}