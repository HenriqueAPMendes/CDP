#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define endl '\n'
#define vi vector<int>
#define ii pair<int,int>
#define iii pair<ii,int>
#define viii vector<iii>
#define vii vector<ii>
#define INF 1123456789012345

#define VAZIO 0
#define PREDIO 1
#define BOMBA 2
#define DESTRUIDO 3

int n;
vector<vi> mapa, vis;

void explodir(int i, int j, int starti, int startj, int r){
    vis[i][j] = 1;
    double dist = (i-starti)*(i-starti) + (j-startj)*(j-startj);
    if (dist > r*r) return;

    if (mapa[i][j] == PREDIO) mapa[i][j] = DESTRUIDO;
    else mapa[i][j] = BOMBA;

    if (i > 0 && !vis[i-1][j]) explodir(i-1,j,starti, startj, r);
    if (i < n-1 && !vis[i+1][j]) explodir(i+1,j,starti, startj, r);
    if (j > 0 && !vis[i][j-1]) explodir(i,j-1,starti, startj, r);
    if (j < n-1 && !vis[i][j+1]) explodir(i,j+1,starti, startj, r);
}


void solve(){
    cin >> n;
    mapa = vis = vector<vi>(n, vi(n, VAZIO));

    int ned; cin >> ned;
    vii ed(ned);
    for (int i = 0; i < ned; i++){
        cin >> ed[i].first >> ed[i].second;
        mapa[ed[i].first][ed[i].second] = PREDIO;
    }
        
    int b; cin >> b;
    viii bomb(b);
    for (int i = 0; i < b; i++)
        cin >> bomb[i].first.first >> bomb[i].first.second >> bomb[i].second;

    for (auto b : bomb){
        int i = b.first.first;
        int j = b.first.second;
        int r = b.second;
        explodir(i,j,i,j,r);
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (mapa[i][j] == PREDIO) cout << "o ";
            if (mapa[i][j] == DESTRUIDO) cout << "# ";
            if (mapa[i][j] == BOMBA) cout << "* ";
            if (mapa[i][j] == VAZIO) cout << ". ";
        }
        cout << endl;
    }

}

signed main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int t; cin >> t;
    while(t--) solve();

    return 0;
}