#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define endl '\n'
#define vi vector<int>
#define ii pair<int,int>

signed main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n, m; cin >> n >> m;
    vector<vector<char>> mat(n, vector<char>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> mat[i][j];

    string ans = "";
    int i = n-1;
    int j = 0;
    
    while(i > 0){
        int startI = i;
        j = 0;
        while(i < n && j < m){
            ans += mat[i][j];
            i++; j++;
        }
        i = startI - 1;;
    }
    i = 0;
    j = 0;
    while(j < m){
        int startJ = j;
        i = 0;
        while(i < n && j < m){
            ans += mat[i][j];
            i++; j++;
        }
        j = startJ + 1;
    }

    cout << ans << endl;

    return 0;
}