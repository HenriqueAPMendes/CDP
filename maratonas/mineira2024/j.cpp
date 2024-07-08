#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define endl '\n'
#define vi vector<int>
#define vvi vector<vi>
#define ii pair<int,int>

void solve(){
    int n, D;
    cin >> n >> D;
    vi d(n);
    for (int i = 0; i < n; i++) cin >> d[i];

    // calcula lista de vetores de paes por dia

    vvi paes(212);
    vi p(212); // marca em quantos locais aparece
    for (int i = 0; i < n ; i++){
        int t1 = d[i]+D;
        int t2 = d[i]-D;
        paes[t1].push_back(i);
        if (d[i] >= D)
            paes[t2].push_back(i), p[i] = 2;
        else
            p[i] = 1;
    }
    // vetor p guarda quantas opcoes esse i pode ser comido,
    // garante escolha gulosa do descendo
    int ans = 0;
    for (int i = 0; i < 212; i++){
        if (paes.size() == 0) continue;
        // escolhe o pao a comer
        // primeiro tenta os que estao endurecendo
        bool ok = false;
        for (auto pao : paes[i])
            if (p[pao] e== 1) {ok=true; p[pao] = 0; ans++; break;}
        
        if (ok) continue; // comeu
        
        // depois os que estao amolecendo 
        for (auto pao : paes[i])
            if (p[pao] != 0) {ok=true; p[pao] = 0; ans++; break;}
        
    }
    cout << ans << endl;
}

signed main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    solve();
    return 0;
}