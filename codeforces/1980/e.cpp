#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define endl '\n'
#define vi vector<int>
#define vvi vector<vi>

void solve(){
    int n, m; 
    cin >> n >> m;

    vvi a(n, vi(m)), b(n, vi(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> b[i][j];

    set<set<int>> rowsA, rowsB, colsA, colsB;

    for (int i = 0; i < n; i++){
        set<int> sA, sB;
        for (int j = 0; j < m; j++){
            sA.insert(a[i][j]);
            sB.insert(b[i][j]);
        }
        rowsA.insert(sA);
        rowsB.insert(sB);
    }

    for (int j = 0; j < m; j++){
        set<int> sA, sB;
        for (int i = 0; i < n; i++){
            sA.insert(a[i][j]);
            sB.insert(b[i][j]);
        }
        colsA.insert(sA);
        colsB.insert(sB);
    }

    for (auto s : rowsA)
        if (rowsB.find(s) == rowsB.end()) {cout << "NO" << endl; return ;}


    for (auto s : colsA)
        if (colsB.find(s) == colsB.end()) {cout << "NO" << endl; return ;}
    

    cout << "YES" << endl;
}

signed main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}