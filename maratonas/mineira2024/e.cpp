#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define endl '\n'
#define vi vector<int>
#define vvi vector<vi>
#define ii pair<int,int>

vvi casas(212345);

void solve(){
    int n; cin >> n;
    for (int i = 0; i < n; i++){
        int r, c;
        cin >> r >> c;
        casas[r].push_back(c);
    }

    for (int i = 0; i < 212345; i++){
        // para cada rua, pega a media e a distancia ate a media
        int avg = 0;
        for (auto c : casas[i])
            avg += c;
        avg /= casas[i].size();
    }
}

signed main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    solve();
    return 0;
}