#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

const int MAX = 1123;
vector<vector<int>> v(MAX,vector<int>(MAX,0));

void visit(int i, int j, int n, int m, int vis){
    if (i < 0 or i >= n or j < 0 or j >= m) return;
    if (v[i][j] == 0) return;
    if (v[i][j] == vis) return;
    v[i][j] = vis;
    visit(i-1,j,n,m,vis);
    visit(i+1,j,n,m,vis);
    visit(i,j-1,n,m,vis);
    visit(i,j+1,n,m,vis);
}

int main (){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n, m;
    char c;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++){
            cin >> c;
            if (c == '.') v[i][j] = 1;
        }


    int ans = 2;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (v[i][j] == 0) continue;
            if (v[i][j] > 1) continue;
            visit(i,j,n,m,ans++);
        }
    }


    cout << ans-2 << endl;

    return 0;
}