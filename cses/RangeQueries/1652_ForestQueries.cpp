#include <bits/stdc++.h>
using namespace std;

#define MAXN 1123

vector<vector<int>> f(MAXN, vector<int> (MAXN, 0));
vector<vector<long long>> pre_sum(MAXN, vector<long long> (MAXN, 0));

// PROVAVEL ERRO NA ENTRADA

int main (){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n, q;
    char c;
    cin >> n >> q;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> c;
            if (c == '*') f[i][j] = 1;
        }
            getchar(); // \n
    }
    
    for (int i = 0; i < n; i++){
        pre_sum[i][0] = f[i][0];
        for (int j = 1; j < n; j++)
            pre_sum[i][j] = pre_sum[i][j-1] + f[i][j];    
    }

    // cout << "forest:\n";
    // for (int i = 0; i < n; i++){
    //     for (int j = 0; j < n; j++)
    //         cout << f[i][j] << " ";
    //     cout << endl;
    // }

    // cout << "prefix sum:\n";
    // for (int i = 0; i < n; i++){
    //     for (int j = 0; j < n; j++)
    //         cout << pre_sum[i][j] << " ";
    //     cout << endl;
    // }

    int y1, x1, y2, x2;
    long long ans;    
    while(q--){
        ans = 0;
        cin >> y1 >> x1 >> y2 >> x2;
        y1--;x1--;y2--;x2--;
        for (int i = y1; i <= y2; i++){
            if (x1) ans += pre_sum[i][x2] - pre_sum[i][x1-1];
            else ans += pre_sum[i][x2];
        }
        //cout << ans << '\n';   
    }

    return 0;
}