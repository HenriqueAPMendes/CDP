#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define vi vector<int>
#define ii pair<int,int>
#define endl '\n'
#define vii vector<ii>

void solve(){
    int n, m, k;
    string s;
    cin >> n >> k >> m;
    cin >> s;

    vector<vi> presum(26, vi(m));

    vii pos(k, {-1,-1}); // salva primeira e ultima aparicao de cada letra
    for (int i = 0; i < m; i++){
        if (pos[s[i]-'a'].first == -1) pos[s[i]-'a'].first = i;
        else pos[s[i]-'a'].second = i; 
    }

    for (int i = 0; i < m; i++)
        presum[s[i]-'a'][i]++;

    for (int i = 0; i < 26; i++)
        for (int j = 1; j < m; j++)
            presum[i][j] += presum[i][j-1];

    
    bool valid = true;
    string ans;

    for (int i = 0; i < k; i++){ // para cada letra
        for (int j = 0; j < k; j++){
            auto [f,s] = pos[j];
            if (f == -1 or s == 0){ 
                valid = false; 
                for (int k = 0; k < n; k++) ans += 'a'+j;
                break; 
            }
            if (s == -1 && f != -1) s = f; 

            if (presum[j][m-1] - presum[j][f] < n-1){ // se a letra j aparece menos do que n-1 vezes depois de f
                valid = false; 
                for (int k = 0; k < n; k++) ans += 'a'+j;
                break; 
            } 
            if (presum[j][s-1] < n-1){ // se a letra j aparece menos do que n-1 vezes antes de s
                valid = false; 
                for (int k = 0; k < n; k++) ans += 'a'+j;
                break; 
            } 

        }
    }
    if (valid) cout << "YES" << endl;
    else cout << "NO" << endl << ans.substr(0,n) << endl;
}

signed main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int t; cin >> t;
    while(t--) solve();

    return 0;
}