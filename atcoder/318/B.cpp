#include <bits/stdc++.h>
using namespace std;

// Brute force way

/*
int main(){

    int m[101][101];
    
    // zera tudo
    for (int i = 0; i < 101; i++)
        for (int j = 0; j < 101; j++)
            m[i][j] = 0;

    int a,b,c,d,N;
    cin >> N;
    // leitura de N retangulos
    for (int i = 0; i < N; i++){
        cin >> a >> b >> c >> d;
        for (int j = a; j < b; j++)
            for (int k = c; k < d; k++)
                m[j][k] = 1;
    }                

    // soma tudo
    int s = 0;
    for (int i = 0; i < 101; i++)
        for (int j = 0; j < 101; j++)
            s += m[i][j];

    cout << s << endl;

    return 0;
}
*/


// Difference array solution

#define MAX 112

int diff[MAX][MAX], grid[MAX][MAX], dcol[MAX];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N; cin >> N;
    while(N--){
        int a, b, c, d, x1, x2, y1, y2;
        cin >> a >> b >> c >> d;
        x1 = a; y1 = c; x2 = b; y2 = d;
        diff[x1][y1]++;
        diff[x1][y2]--;

        diff[x2][y1]--;
        diff[x2][y2]++;
    }
    memset(dcol, 0, sizeof(dcol));

    int ans = 0;
    for (int i = 0; i <= 100; i++){
        int delta = 0;
        for (int j = 0; j <= 100; j++){
            dcol[j] += diff[i][j];
            delta += dcol[j];
            grid[i][j] += delta;
            ans += (grid[i][j] > 0);
        }
    }

    cout << ans << endl;

    return 0;
}