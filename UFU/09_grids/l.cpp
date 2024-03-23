#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define endl '\n'
#define vi vector<int>
#define ii pair<int,int>
#define vii vector<ii>
#define INF 1123456789012345

void solve(){
    int n; cin >> n;
    vector<vector<char>> board(n, vector<char>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> board[i][j];

    //checa linhas
    bool ok = true;
    map<char, int> freq;
    for (int i = 0; i < n; i++){
        freq.clear();
        for (int j = 0; j < n; j++){
            freq[board[i][j]]++;
            if (freq[board[i][j]] > 1) ok = false;
        }
    }

    // checa colunas
    for (int j = 0; j < n; j++){
        freq.clear();
        for (int i = 0; i < n; i++){
            freq[board[i][j]]++;
            if (freq[board[i][j]] > 1) ok = false;
        }
    }

    cout << (ok ? "sim" : "nao") << endl;
}

signed main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int t; cin >> t;
    while(t--) solve();

    return 0;
}