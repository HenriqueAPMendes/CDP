#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define endl '\n'
#define vi vector<int>
#define ii pair<int,int>

void solve(){
    int k; cin >> k;
    string s; cin >> s;
    vi d(k);
    for (int i = 0; i < k; i++) d[i] = s[i]-'A';

    int n; cin >> n;
    vector<vi> answers(n, vi(k));
    for (int i = 0; i < n; i++){
        cin >> s;
        for (int j = 0; j < k; j++) answers[i][j] = s[j]-'A';
    }    

    // para cada questao
    int ans = 0;
    for (int i = 0; i < k; i++){
        vi freq(26);
        int maxFreq = 0;
        for (int j = 0; j < n; j++){
            freq[answers[j][i]]++;
        }
        for (int j = 0; j < 26; j++){
            if (j == d[i]) continue;
            maxFreq = max(maxFreq, freq[j]);
        }
        ans += maxFreq;
    }

    cout << ans << endl;
}

signed main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    solve();
    return 0;
}