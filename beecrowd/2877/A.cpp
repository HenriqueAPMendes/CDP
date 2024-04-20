#include <bits/stdc++.h>
using namespace std;

#define MAX 112

int grundy[MAX][MAX];
int mov[3*MAX]; // vetor de flags

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    for (int i = 0; i < MAX; i++)
        for (int j = 0; j < MAX; j++){
            if (i == j) continue;
            memset(mov, 0, sizeof mov);
            for (int u = 1; u < j; u++)
                if (i != j-u) mov[grundy[i][j-u]] |= 1;
            for (int u = 1; u < i; u++)
                if (i-u != j) mov[grundy[i-u][j]] |= 1;
            for (int u = 1; u < min(i, j); u++)
                mov[grundy[i-u][j-u]] |= 1;

            int mex = 0;
            while(mov[mex]) mex++;
            grundy[i][j] = mex;

        }


    int N, win = 0, ans = 0;
    cin >> N;

    for (int i = 0; i < N; i++){
        int l, c;
        cin >> l >> c;

        if (l == c) win |= 1;// fiagonal principal do tabuleiro
        else ans ^= grundy[l][c];
    }

    if (win || ans) cout << "Y\n" ;
    else cout << "N\n";

    return 0;
}